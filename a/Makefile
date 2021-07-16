include config.mk

all: $(OUTPUT) build unittests

build:
	@$(CXX) $(CXXFLAGS) -o $(OUTPUT)/$(PROGNAME) src/*.cpp -I include/
	@$(ECHO_COMPILE)

unittests:
	@$(CXX) $(UTCXXFLAGS) -o $(OUTPUT)/$(PROGNAME_UT) $(filter-out src/main.cpp,$(wildcard src/*.cpp)) $(UNITTEST_DIR)/*.cpp -I include/ -I $(UNITTEST_DIR)/
	@$(ECHO_UT_COMPILE)

$(OUTPUT):
	$(SILENT_MKDIR)mkdir $(OUTPUT)

clean:
	rm -f $(OUTPUT)/$(PROGNAME) $(OUTPUT)/$(PROGNAME_UT)

format:
	find . -iname *.h -o -iname *.cpp | xargs clang-format -i -verbose -style=file


start: $(OUTPUT)
	$(SILENT_MKDIR)mkdir src include $(UNITTEST_DIR)
	@curl https://raw.githubusercontent.com/catchorg/Catch2/7cbd0b587a24e5cbb9a7da9dd288f0532abfc57a/single_include/catch.hpp > $(UNITTEST_DIR)/catch.hpp
	@touch $(UNITTEST_DIR)/tests.cpp
	@echo "#define CATCH_CONFIG_MAIN\n#include \"catch.hpp\"\n" > $(UNITTEST_DIR)/main.cpp

help:
	@echo "Um die Entwicklung zu starten nutzen Sie \"make start\" damit wird die Verzeichnissstruktur erstellt."
	@echo "Zum compilieren reicht \"make\""
