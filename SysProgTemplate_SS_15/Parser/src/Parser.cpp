/*
 * Parser.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#include "../includes/Parser.h"
#include "../includes/ParseTree.h"
#include "../includes/Node.h"
#include "../includes/Leaf.h"
#include <stdexcept>
#include <fstream>
using namespace std;

Parser::~Parser() {
}

Parser::Parser(Scanner* scan) {
	this->scanner = scan;
	this->tok = this->scanner->nextToken(false);
	this->tree = new ParseTree();
	this->labelCounter = 0;
	this->index = -1;
	this->idx = -1;
}

void Parser::nextToken() {
	this->tok = this->scanner->nextToken(false);
}

void Parser::nextDeclToken() {
	this->tok = this->scanner->nextToken(true);
}

bool Parser::isPROG(std::ofstream& out) {
	Node* prog = new Node(tok);
	prog->setType(Node::Prog);
	if ((this->isDECLS(prog, out) && this->tok == NULL)
			|| this->isSTATEMENTS(prog, out)) {
		tree->setProg(prog);
		printCode(out, "NOP\n");
		printCode(out, "STP");
		return true;
	}
//	 else if (this->isSTATEMENTS()) {
//		tree->setProg(prog);
//		return true;
//	}
//	else if (this->scanner->getStop()) {
//		tree->setProg(prog);
//		return true;
//	}
	if (this->tok != NULL) {
		fprintf(stderr, "\nunexpected Token Line: %d Column: %d Symbol: %s\n",
				tok->getLine(), tok->getColumn(), tok->getInfokey());
	} else {
		fprintf(stderr, "\nunexpected File End.\n");
	}
	return false;
}

bool Parser::isDECLS(Node* node, std::ofstream& out) {
	Node* decls = new Node(tok);
	decls->setType(Node::Decls);
	if (this->tok == NULL) {
		node->addNode(decls);
		return true;
	} else if (this->isDECL(decls, out)) {
		if (accept(Semicolon, decls)) { //switch to false when there is 1 decl and continue with a statement
			if (this->isDECLS(decls, out)) {
				node->addNode(decls);
				return true;
			}
		}
	}
	return false;
}

bool Parser::isSTATEMENTS(Node* node, std::ofstream& out) {
	Node* stats = new Node(tok);
	stats->setType(Node::Statments);
	if (this->isSTATEMENT(stats, out)) {
		if (accept(Semicolon, stats)) { // where the fuck is mah ;)
			if (this->tok == NULL) {
				node->addNode(stats);
				return true;
			} else if (this->isSTATEMENTS(stats, out)) {
				node->addNode(stats);
				return true;
			} else if (this->tok != NULL
					&& this->tok->gettype() == BracesRIGHT) {
				node->addNode(stats);
				return true;
			}
		}
	} else if (this->tok != NULL && this->tok->gettype() == BracesRIGHT) {
		node->addNode(stats);
		return true;
	}
	return false;
}

bool Parser::isDECL(Node* node, std::ofstream& out) {
	Node* decl = new Node(tok);
	decl->setType(Node::Decl);
	if (acceptDecl(KeywordINT, decl)) {
		if (accept(SquareBracketLEFT, decl)) {
			int index = tok->getValue();
			if (accept(Integer, decl)) {
				if (acceptDecl(SquareBracketRIGHT, decl)) {
					char* identifier = tok->getInfokey();
					if (accept(Identifier, decl)) {
						printCode(out, "DS $");
						printCode(out, identifier);
						printCode(out, " ");
						printIntCode(out, index);
						printCode(out, "\n");
						node->addNode(decl);
						return true;
					}
				}
			} else {
				fprintf(stderr, "\nNo valid Dimension: %s", tok->getInfokey());
				nextToken();
				if (tok->getValue() != -1) {
					fprintf(stderr, "%d Line: %d Column: %d\n", tok->getValue(),
							tok->getLine(), tok->getColumn());
				} else {
					fprintf(stderr, " Line: %d Column: %d\n", tok->getLine(),
							tok->getColumn());
				}
				throw logic_error("No valid Dimension");
			}
		}
		char* identifier = tok->getInfokey();
		if (accept(Identifier, decl)) {
			node->addNode(decl);
			printCode(out, "DS $");
			printCode(out, identifier);
			printCode(out, " 1\n");
			return true;
		}
	}
	return false;
}

bool Parser::isSTATEMENT(Node* node, std::ofstream& out) {
	Node* stat = new Node(tok);
	stat->setType(Node::Statement);
	char* identifier = tok->getInfokey();
	if (accept(Identifier, stat)) {
		if (accept(Assign, stat)) {
			if (isEXPS(stat, out, false)) {
				printCode(out, "LA $");
				printCode(out, identifier);
				printCode(out, "\n");
				printCode(out, "STR\n");
				node->addNode(stat);
				return true;
			}
		}
		std::ofstream indexfile;
		if (isINDEX(stat, indexfile)) {
			if (accept(Assign, stat)) {
				if (isEXPS(stat, out, false)) {
					printCode(out, "LA $");
					printCode(out, identifier);
					printCode(out, "\n");
					if (index != -1) {
						printCode(out, "LC ");
						printIntCode(out, index);
						printCode(out, "\n");
					} else if (NULL != infokey && strcmp(infokey, "")) {
						printCode(out, "LA $");
						printCode(out, infokey);
						printCode(out, "\n");
						printCode(out, "LV\n");
					}
					if (idx != -1) {
						printCode(out, "LC ");
						printIntCode(out, idx);
						printCode(out, "\n");
					} else if (NULL != ikey && strcmp(ikey, "")) {
						printCode(out, "LA $");
						printCode(out, ikey);
						printCode(out, "\n");
						printCode(out, "LV\n");
					}
					if (opToken != NULL) {
						writeOPCode(opToken, index, idx, out);
					}
					printCode(out, "ADD\n");
					printCode(out, "STR\n");
					node->addNode(stat);
					return true;
				}
			}
		}
	}
	if (accept(BracesLEFT, stat)) {
		if (isSTATEMENTS(stat, out)) {
			if (accept(BracesRIGHT, stat)) {
				node->addNode(stat);
				return true;
			}
		}
	} else if (accept(KeywordWRITE, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			if (isEXPS(stat, out, false)) {
				if (accept(ParenthesesRIGHT, stat)) {
					printCode(out, "PRI\n");
					node->addNode(stat);
					return true;
				}
			}
		}
	} else if (accept(KeywordREAD, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			char* identifier = tok->getInfokey();
			if (accept(Identifier, stat)) {
				printCode(out, "REA\n");
				printCode(out, "LA $");
				printCode(out, identifier);
				printCode(out, "\n");
				if (isINDEX(stat, out)) {
					if (accept(ParenthesesRIGHT, stat)) {
						printCode(out, "ADD\n");
						printCode(out, "STR\n");
						node->addNode(stat);
						return true;
					}
				} else if (accept(ParenthesesRIGHT, stat)) {
					printCode(out, "STR\n");
					node->addNode(stat);
					return true;
				}
			}
		}
	} else if (accept(KeywordIF, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			if (isEXPS(stat, out, false)) {
				if (accept(ParenthesesRIGHT, stat)) {
					printCode(out, "JIN #label");
					printIntCode(out, this->labelCounter);
					printCode(out, "\n");
					int labelIfCounter = labelCounter;
					this->labelCounter++;
					if (isSTATEMENT(stat, out)) {
						printCode(out, "JMP #label");
						printIntCode(out, this->labelCounter);
						printCode(out, "\n");
						int labelElseCounter = labelCounter;
						this->labelCounter++;
						if (accept(KeywordELSE, stat)) {
							printCode(out, "#label");
							printIntCode(out, labelIfCounter);
							printCode(out, " NOP\n");
							if (isSTATEMENT(stat, out)) {
								printCode(out, "#label");
								printIntCode(out, labelElseCounter);
								printCode(out, " NOP\n");
								node->addNode(stat);
								return true;
							}
						}
					}
				}
			}
		}
	} else if (accept(KeywordWHILE, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			printCode(out, "#label");
			printIntCode(out, labelCounter);
			printCode(out, " NOP\n");
			int labelWhileCounter = labelCounter;
			this->labelCounter++;
			if (isEXPS(stat, out, false)) {
				if (accept(ParenthesesRIGHT, stat)) {
					printCode(out, "JIN #label");
					printIntCode(out, this->labelCounter);
					printCode(out, "\n");
					int labelJumpOutCounter = labelCounter;
					this->labelCounter++;
					if (isSTATEMENT(stat, out)) {
						printCode(out, "JMP #label");
						printIntCode(out, labelWhileCounter);
						printCode(out, "\n");
						printCode(out, "#label");
						printIntCode(out, labelJumpOutCounter);
						printCode(out, " NOP\n");
						node->addNode(stat);
						return true;
					}
				}
			}
		}
	}
//	 else if (accept(Minus, stat)) { TODO: Why check this in statement?
//		node->addNode(stat);
//		return true;
//	} else if (accept(Colon, stat)) {
//		node->addNode(stat);
//		return true;
//	} else if (accept(Star, stat)) {
//		node->addNode(stat);
//		return true;
//	} else if (accept(And, stat)) {
//		node->addNode(stat);
//		return true;
//	}
	return false;
}

bool Parser::isEXPS(Node* node, std::ofstream& out, bool isIndex) {
	Node* exps = new Node(tok);
	exps->setType(Node::Exp);
	int a = tok->getValue();
	if (isIndex) {
		index = tok->getValue();
		infokey = tok->getInfokey();
	}
	if (isEXP(exps, out)) {
		Token* op = tok;
		if (isIndex) {
			opToken = tok;
		}
		if (isOP(exps, out)) {
			if (isIndex) {
				idx = tok->getValue();
				ikey = tok->getInfokey();
			}
			int b = tok->getValue();
			if (isEXPS(exps, out, false)) {
				writeOPCode(op, a, b, out);
				node->addNode(exps);
				return true;
			}
		} else {
			node->addNode(exps);
			return true;
		}
	}
	return false;
}

bool Parser::isEXP(Node* node, std::ofstream& out) {
	Node* exp = new Node(tok);
	exp->setType(Node::Exp2);
	int index = tok->getValue();
	char* identifier = tok->getInfokey();
	if (accept(Integer, exp)) {
		node->addNode(exp);
		printCode(out, "LC ");
		printIntCode(out, index);
		printCode(out, "\n");
		return true;
	} else if (accept(Identifier, exp)) {
		printCode(out, "LA $");
		printCode(out, identifier);
		printCode(out, "\n");
		if (isINDEX(exp, out)) {
			printCode(out, "ADD\n");
			printCode(out, "LV");
			printCode(out, "\n");
			node->addNode(exp);
			return true;
		} else if (this->tok->gettype() == Semicolon
				|| this->tok->gettype() == ParenthesesRIGHT || checkOP()
				|| this->tok->gettype() == KeywordELSE) {
			printCode(out, "LV");
			printCode(out, "\n");
			node->addNode(exp);
			return true;
		} else if (this->tok->gettype() == SquareBracketRIGHT) {
			node->addNode(exp);
			return true;
		}
	} else if (accept(Minus, exp)) {
		printCode(out, "LC 0\n");
		if (isEXP(exp, out)) {
			printCode(out, "SUB\n");
			node->addNode(exp);
			return true;
		}
//	} else if (accept(Plus, exp)) { TODO: why check for + EXP?
//		if (isEXP(exp)) {
//			node->addNode(exp);
//			return true;
//		}
	} else if (accept(ExclamationMark, exp)) {
		if (isEXP(exp, out)) {
			printCode(out, "NOT\n");
			node->addNode(exp);
			return true;
		}
	}
	if (accept(ParenthesesLEFT, exp)) {
		if (this->isEXPS(exp, out, false)) {
			if (accept(ParenthesesRIGHT, exp)) {
				node->addNode(exp);
				return true;
			}
		}
	}
	return false;
}

bool Parser::isOP(Node* node, std::ofstream& out) {
	Node* op = new Node(tok);
	op->setType(Node::Op);
	if (accept(InequalitySignRIGHT, op)) {
		node->addNode(op);
		return true;
	} else if (accept(Equal, op)) {
		node->addNode(op);
		return true;
	} else if (accept(EqualColonEqual, op)) {
		node->addNode(op);
		return true;
	} else if (accept(Plus, op)) {
		node->addNode(op);
		return true;
	} else if (accept(Minus, op)) {
		node->addNode(op);
		return true;
	} else if (accept(Colon, op)) {
		node->addNode(op);
		return true;
	} else if (accept(Star, op)) {
		node->addNode(op);
		return true;
	} else if (accept(And, op)) {
		node->addNode(op);
		return true;
	} else if (accept(InequalitySignLEFT, op)) {
		node->addNode(op);
		return true;
	}
	return false;
}

bool Parser::checkOP() {
	if (this->tok->gettype() == InequalitySignRIGHT) {
		return true;
	} else if (this->tok->gettype() == Equal) {
		return true;
	} else if (this->tok->gettype() == EqualColonEqual) {
		return true;
	} else if (this->tok->gettype() == Plus) {
		return true;
	} else if (this->tok->gettype() == Minus) {
		return true;
	} else if (this->tok->gettype() == Colon) {
		return true;
	} else if (this->tok->gettype() == Star) {
		return true;
	} else if (this->tok->gettype() == And) {
		return true;
	} else if (this->tok->gettype() == InequalitySignLEFT) {
		return true;
	}
	return false;
}

bool Parser::writeOPCode(Token* token, int toka, int tokb, std::ofstream& out) {
	if (token->gettype() == InequalitySignRIGHT) {
		printCode(out, "LES\n");
		if (toka != tokb) {
			printCode(out, "NOT\n");
		}
		return true;
	} else if (token->gettype() == Equal) {
		printCode(out, "EQU\n");
		return true;
	} else if (token->gettype() == EqualColonEqual) {
		printCode(out, "EQU\n");
		printCode(out, "NOT\n");
		return true;
	} else if (token->gettype() == Colon) {
		printCode(out, "DIV\n");
		return true;
	} else if (token->gettype() == Plus) {
		printCode(out, "ADD\n");
		return true;
	} else if (token->gettype() == Minus) {
		printCode(out, "SUB\n");
		return true;
	} else if (token->gettype() == Star) {
		printCode(out, "MUL\n");
		return true;
	} else if (token->gettype() == And) {
		printCode(out, "AND\n");
		return true;
	} else if (token->gettype() == InequalitySignLEFT) {
		printCode(out, "LES\n");
		return true;
	}
	return false;
}

bool Parser::isINDEX(Node* node, std::ofstream& out) {
	Node* index = new Node(tok);
	index->setType(Node::Index);
	idx=-1;
//	ikey=NULL;
	if (accept(SquareBracketLEFT, index)) {
		if (tok->gettype() != Minus && tok->gettype() != ExclamationMark) {
			if (isEXPS(index, out, true)) {
				if (accept(SquareBracketRIGHT, index)) {
					node->addNode(index);
					return true;
				}
			}
		} else {
			fprintf(stderr, "\nNo valid Dimension: %s", tok->getInfokey());
			nextToken();
			if (tok->getValue() != -1) {
				fprintf(stderr, "%d Line: %d Column: %d\n", tok->getValue(),
						tok->getLine(), tok->getColumn());
			} else {
				fprintf(stderr, " Line: %d Column: %d\n", tok->getLine(),
						tok->getColumn());
			}
			throw logic_error("No valid Dimension");
		}
	}
	return false;
}

bool Parser::accept(TokenType T, Node* node) {
	if (NULL != tok && this->tok->gettype() == T) {
		Leaf* leaf = new Leaf(tok);
		leaf->setTokenType(tok->gettype());
		node->addNode(leaf);
		nextToken();
		return true;
	}
	return false;
}

bool Parser::acceptDecl(TokenType T, Node* node) {
	if (NULL != tok && this->tok->gettype() == T) {
		Leaf* leaf = new Leaf(tok);
		leaf->setTokenType(tok->gettype());
		node->addNode(leaf);
		nextDeclToken();
		return true;
	}
	return false;
}

int Parser::expect(TokenType T) {
	if (this->accept(T, NULL))
		return true;
	return false;
}

void Parser::printCode(std::ofstream& out, const char* code) {
	out << code;
}

void Parser::printIntCode(std::ofstream& out, int code) {
	out << code;
}

