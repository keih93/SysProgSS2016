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
#include <sstream>
using namespace std;

Parser::~Parser() {
}

Parser::Parser(Scanner* scan) {
	this->scanner = scan;
	this->tok = this->scanner->nextToken(false);
	this->tree = new ParseTree();
}

void Parser::nextToken() {
	this->tok = this->scanner->nextToken(false);
}

void Parser::nextDeclToken() {
	this->tok = this->scanner->nextToken(true);
}

bool Parser::isPROG() {
	Node* prog = new Node(tok);
	prog->setType(Node::Prog);
	if ((this->isDECLS(prog) && this->tok == NULL)
			|| this->isSTATEMENTS(prog)) {
		tree->setProg(prog);
		outCode.append("NOP\n");
		outCode.append("STP");
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

bool Parser::isDECLS(Node* node) {
	Node* decls = new Node(tok);
	decls->setType(Node::Decls);
	if (this->tok == NULL) {
		node->addNode(decls);
		return true;
	} else if (this->isDECL(decls)) {
		if (accept(Semicolon, decls)) { //switch to false when there is 1 decl and continue with a statement
			if (this->isDECLS(decls)) {
				node->addNode(decls);
				return true;
			}
		}
	}
	return false;
}

bool Parser::isSTATEMENTS(Node* node) {
	Node* stats = new Node(tok);
	stats->setType(Node::Statments);
	if (this->isSTATEMENT(stats)) {
		if (accept(Semicolon, stats)) { // where the fuck is mah ;)
			if (this->tok == NULL) {
				node->addNode(stats);
				return true;
			} else if (this->isSTATEMENTS(stats)) {
				node->addNode(stats);
				return true;
			} else if (this->tok != NULL
					&& this->tok->gettype() == BracesRIGHT) {
				node->addNode(stats);
				return true;
			}
		}
	}
	return false;
}

bool Parser::isDECL(Node* node) {
	Node* decl = new Node(tok);
	decl->setType(Node::Decl);
	if (acceptDecl(KeywordINT, decl)) {
		if (accept(SquareBracketLEFT, decl)) {
			int index = tok->getValue();
			if (accept(Integer, decl)) {
				if (acceptDecl(SquareBracketRIGHT, decl)) {
					char* identifier = tok->getInfokey();
					if (accept(Identifier, decl)) {
						outCode.append("DS $");
						outCode.append(identifier);
						outCode.append(" ");
						std::ostringstream indexString;
						indexString << index;
						outCode.append(indexString.str());
						outCode.append("\n");
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
			outCode.append("DS $");
			outCode.append(identifier);
			outCode.append(" 1\n");
			return true;
		}
	}
	return false;
}

bool Parser::isSTATEMENT(Node* node) {
	Node* stat = new Node(tok);
	stat->setType(Node::Statement);
	if (accept(Identifier, stat)) {
		if (accept(Assign, stat)) {
			if (isEXPS(stat)) {
				node->addNode(stat);
				return true;
			}
		}
		if (isINDEX(stat)) {
			if (accept(Assign, stat)) {
				if (isEXPS(stat)) {
					node->addNode(stat);
					return true;
				}
			}
		}
	} else if (accept(BracesLEFT, stat)) {
		if (isSTATEMENTS(stat)) {
			if (accept(BracesRIGHT, stat)) {
				node->addNode(stat);
				return true;
			}
		}
	} else if (accept(KeywordWRITE, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			if (isEXPS(stat)) {
				if (accept(ParenthesesRIGHT, stat)) {
					outCode.append("PRI\n");
					node->addNode(stat);
					return true;
				}
			}
		}
	} else if (accept(KeywordREAD, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			if (accept(Identifier, stat)) {
				if (isINDEX(stat)) {
					if (accept(ParenthesesRIGHT, stat)) {
						node->addNode(stat);
						return true;
					}
				} else if (accept(ParenthesesRIGHT, stat)) {
					node->addNode(stat);
					return true;
				}
			}
		}
	} else if (accept(KeywordIF, stat)) {
		if (accept(ParenthesesLEFT, stat)) {
			if (isEXPS(stat)) {
				if (accept(ParenthesesRIGHT, stat)) {
					if (isSTATEMENT(stat)) {
						if (accept(KeywordELSE, stat)) {
							if (isSTATEMENT(stat)) {
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
			if (isEXPS(stat)) {
				if (accept(ParenthesesRIGHT, stat)) {
					if (isSTATEMENT(stat)) {
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

bool Parser::isEXPS(Node* node) {
	Node* exps = new Node(tok);
	exps->setType(Node::Exp);
	int a = tok->getValue();
	if (isEXP(exps)) {
		Token* op = tok;
		if (isOP(exps)) {
			int b = tok->getValue();
			if (isEXPS(exps)) {
				writeOPCode(op, a, b);
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

bool Parser::isEXP(Node* node) {
	Node* exp = new Node(tok);
	exp->setType(Node::Exp2);
	int index = tok->getValue();
	char* identifier = tok->getInfokey();
	if (accept(Integer, exp)) {
		node->addNode(exp);
		outCode.append("LC ");
		std::ostringstream indexString;
		indexString << index;
		outCode.append(indexString.str());
		outCode.append("\n");
		return true;
	} else if (accept(Identifier, exp)) {
		if (isINDEX(exp)) {
			node->addNode(exp);
			return true;
		} else if (this->tok->gettype() == Semicolon
				|| this->tok->gettype() == ParenthesesRIGHT || checkOP()) {
			outCode.append("LA $");
			outCode.append(identifier);
			outCode.append("\n");
			outCode.append("LV");
			outCode.append("\n");
			node->addNode(exp);
			return true;
		} else if (this->tok->gettype() == SquareBracketRIGHT) {
			outCode.append("LA $");
			outCode.append(identifier);
			outCode.append("\n");
			outCode.append("LV");
			outCode.append("\n");
			node->addNode(exp);
			return true;
		}
	} else if (accept(Minus, exp)) {
		outCode.append("LC 0\n");
		if (isEXP(exp)) {
			outCode.append("SUB\n");
			node->addNode(exp);
			return true;
		}
//	} else if (accept(Plus, exp)) { TODO: why check for + EXP?
//		if (isEXP(exp)) {
//			node->addNode(exp);
//			return true;
//		}
	} else if (accept(ExclamationMark, exp)) {
		if (isEXP(exp)) {
			outCode.append("NOT\n");
			node->addNode(exp);
			return true;
		}
	}
	if (accept(ParenthesesLEFT, exp)) {
		if (this->isEXPS(exp)) {
			if (accept(ParenthesesRIGHT, exp)) {
				node->addNode(exp);
				return true;
			}
		}
	}
	return false;
}

bool Parser::isOP(Node* node) {
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

bool Parser::writeOPCode(Token* tok, int toka, int tokb) {
	if (this->tok->gettype() == InequalitySignRIGHT) {
		outCode.append("LES\n");
		if (toka != tokb) {
			outCode.append("NOT\n");
		}
		return true;
	} else if (this->tok->gettype() == Equal) {
		outCode.append("EQU\n");
		return true;
	} else if (this->tok->gettype() == Colon) {
		outCode.append("DIV\n");
		return true;
	} else if (this->tok->gettype() == Plus) {
		outCode.append("ADD\n");
		return true;
	} else if (this->tok->gettype() == Minus) {
		outCode.append("SUB\n");
		return true;
	} else if (this->tok->gettype() == Star) {
		outCode.append("MUL\n");
		return true;
	} else if (this->tok->gettype() == And) {
		outCode.append("AND\n");
		return true;
	} else if (this->tok->gettype() == InequalitySignLEFT) {
		outCode.append("LES\n");
		return true;
	}
	return false;
}

bool Parser::isINDEX(Node* node) {
	Node* index = new Node(tok);
	index->setType(Node::Index);
	if (accept(SquareBracketLEFT, index)) {
		if (tok->gettype() != Minus && tok->gettype() != ExclamationMark) {
			if (isEXPS(index)) {
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

void Parser::printOutCode() {
	printf("%s", outCode.c_str());
}
