/*
 * Parser.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#include "../includes/Parser.h"
#include "../includes/ParseTree.h"
#include "../includes/Node.h"

Parser::~Parser() {
}

Parser::Parser(Scanner* scan) {
	this->parenthesesCounter = 0;
	this->scanner = scan;
	this->tok = this->scanner->nextToken();
}

void Parser::nextToken() {
	this->tok = this->scanner->nextToken();
}

bool Parser::isPROG() {
	//Node* prog = new Node(tok);
	//prog->setType(Node::Prog);
	//ParseTree* tree = new ParseTree(prog);
	//if (this->isDECLS(prog)) {
	if (this->isDECLS()) {
		if (this->isSTATEMENTS()) {
			return true;
		}
	} else if (this->isSTATEMENTS()) {
		return true;

	} else if (this->scanner->getStop()) {
		return true;
	}
	return false;
}

//bool Parser::isDECLS(Node* prog) {
bool Parser::isDECLS() {
	//Node* decls = new Node(Node::Decls, tok);
	if (this->isDECL()) {
		if (accept (Semicolon)) { //switch to false when there is 1 decl and continue with a statement
			//if (this->isDECLS(prog)) {
			if (this->isDECLS()) {
			//	prog->addNode(decls);
				printf("add Decls");
				return true;
			} else {
			//	prog->addNode(decls);
				printf("add Decls");
				return true;
			}
		}
	}
	return false;
}

bool Parser::isSTATEMENTS() {
	if (this->isSTATEMENT()) {
		if (accept (Semicolon)) { // where the fuck is mah ;
			if (this->isSTATEMENTS()) {
				return true;
			} else {
				return true;
			}
		}
	}
	return false;
}

bool Parser::isDECL() {
	if (accept (KeywordINT)) {
		if (accept (SquareBracketLEFT)) {
			if (accept (Integer)) {
				if (accept (SquareBracketRIGHT)) {
					if (accept (Identifier)) {
						return true;
					}
				}
			}
		} else if (accept (Identifier)) {
			return true;
		}
	}
	return false;
}

bool Parser::isSTATEMENT() {
	if (accept (Identifier)) {
		if (accept (Assign)) {
			if (isEXPS()) {
				return true;
			}
		}
		if (accept (SquareBracketLEFT)) {
			if (isEXP()) {
				if (accept (SquareBracketRIGHT)) {
					if (accept (Assign)) {
						if (isEXP()) {
							return true;
						}
					}
				}
			}
		}
	} else if (accept (BracesLEFT)) {
		if (isSTATEMENTS()) {
			if (accept (BracesRIGHT)) {
				return true;
			}
		}
	} else if (accept (KeywordWRITE)) {
		if (accept (ParenthesesLEFT)) {
			if (isEXP()) {
				if (accept (ParenthesesRIGHT)) {
					return true;
				}
			}
		}
	} else if (accept (KeywordREAD)) {
		if (accept (ParenthesesLEFT)) {
			if (accept(Identifier)) {
				if (accept (ParenthesesRIGHT)) {
					return true;
				}
			}
		}
	} else if (accept (Minus)) {
		return true;
	} else if (accept (Colon)) {
		return true;
	} else if (accept (Star)) {
		return true;
	} else if (accept (And)) {
		return true;
	}
	return false;
}

bool Parser::isEXPS() {
	if (isEXP()) {
		if (isOP()) {
			if (isEXP()) {
				return true;
			}
		} else
			return true;
	}
	return false;
}

bool Parser::isEXP() {
	if (accept (Integer)) {
		return true;
	} else if (accept (Identifier)) {
		return true;
	} else if (accept (Minus)) {
		if (isEXP()) {
			return true;
		}
	} else if (accept (Plus)) {
		if (isEXP()) {
			return true;
		}
	} else if (accept (ExclamationMark)) {
		if (isEXP()) {
			return true;
		}
	}
	while (accept (ParenthesesLEFT)) {
		this->parenthesesCounter++;
		if (this->isEXP()) {
			while (this->parenthesesCounter > 0 && accept(ParenthesesRIGHT) == 1) {
				this->parenthesesCounter--;
				if (this->parenthesesCounter == 0
						&& accept(ParenthesesRIGHT) == 0) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Parser::isOP() {
	if (accept (InequalitySignRIGHT))
		return true;
	else if (accept (Equal))
		return true;
	else if (accept (EqualColonEqual))
		return true;
	else if (accept (Plus))
		return true;
	else if (accept (Minus))
		return true;
	else if (accept (Colon))
		return true;
	else if (accept (Star))
		return true;
	else if (accept (And))
		return true;
	else if (accept (InequalitySignLEFT))
		return true;
	return false;
}

int Parser::accept(TokenType T) {
	if (this->tok->gettype() == T) {
		nextToken();
		return true;
	}
	return false;
}

int Parser::expect(TokenType T) {
	if (this->accept(T))
		return true;
	return false;
}

