# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


AUTOMATDIR = ../Automat

BUFFERDIR = ../Buffer

SYMBOLTABLEDIR = ../Symboltable

SCANNERDIR = ../Scanner



## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Parser.o \
	$(OBJDIR)/Node.o \
	$(OBJDIR)/Leaf.o \
	$(OBJDIR)/ParseTree.o
	#$(OBJDIR)/xxn.o


## Variante mit wenig Makefile-Kenntnissen
# 
## linken der Object-files 
#makeTestParser: $(OBJDIR)/Parser.o $(OBJDIR)/TestParser.o
#	g++ -g $(OBJDIR)/Parser.o $(OBJDIR)/TestParser.o   
#	$(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o 
#	$(SCANNERDIR)/$(OBJDIR)/*.o $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
#	 -o $(BINDIRTEST)/ParserTest
##	
##	
##	
### compilieren der source-files
#$(OBJDIR)/Parser.o :  $(SRCDIR)/Parser.cpp $(HEADERDIR)/Parser.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $@  $<
#	g++ -g  -c -Wall  -o $(OBJDIR)/Parser.o  $(SRCDIR)/Parser.cpp
#	cp $(OBJDIR)/Parser.o $(PROJECTOBJDIR)/Parser
##
#
	
	
# Variante mit guten Makefile-Kenntnissen
makeTestParser: $(OBJS) ParserTest

	
$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


ParserTest: $(SRCDIR)/TestParser.cpp $(HEADERDIR)/Parser.h
	g++ -g  -c -Wall src/TestParser.cpp -o $(BINDIRTEST)/TestParser.o  
	g++ -g $(BINDIRTEST)/TestParser.o $(OBJDIR)/*.o $(SCANNERDIR)/$(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/ParserTest

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

cleanParser:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestParser


