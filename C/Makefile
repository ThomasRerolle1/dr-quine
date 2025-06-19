# Makefile principal pour Dr_Quine
# Compile tous les sous-projets

# Couleurs
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

# Répertoires des projets
PROJECTS = colleen grace sully

# Règle par défaut
all: $(PROJECTS)
	@echo "$(GREEN)All Dr_Quine projects compiled successfully!$(RESET)"

# Compilation de chaque projet
colleen:
	@echo "$(BLUE)Compiling Colleen...$(RESET)"
	@$(MAKE) -C colleen
	@echo "$(GREEN)Colleen compiled$(RESET)"

grace:
	@echo "$(BLUE)Compiling Grace...$(RESET)"
	@$(MAKE) -C grace
	@echo "$(GREEN)Grace compiled$(RESET)"

sully:
	@echo "$(BLUE)Compiling Sully...$(RESET)"
	@$(MAKE) -C sully
	@echo "$(GREEN)Sully compiled$(RESET)"

# Tests pour chaque projet
test: test-colleen test-grace test-sully
	@echo "$(GREEN)All tests completed!$(RESET)"

test-colleen: colleen
	@echo "$(YELLOW)Testing Colleen...$(RESET)"
	@$(MAKE) -C colleen diff

test-grace: grace
	@echo "$(YELLOW)Testing Grace...$(RESET)"
	@$(MAKE) -C grace diff

test-sully: sully
	@echo "$(YELLOW)Testing Sully...$(RESET)"
	@$(MAKE) -C sully diff

# Nettoyage de tous les projets
clean:
	@echo "$(BLUE)Cleaning all projects...$(RESET)"
	@$(MAKE) -C colleen clean
	@$(MAKE) -C grace clean
	@$(MAKE) -C sully clean
	@echo "$(GREEN)All projects cleaned$(RESET)"

fclean:
	@echo "$(BLUE)Full clean of all projects...$(RESET)"
	@$(MAKE) -C colleen fclean
	@$(MAKE) -C grace fclean
	@$(MAKE) -C sully fclean
	@echo "$(GREEN)All projects fully cleaned$(RESET)"

# Recompilation complète
re: fclean all

# Compilation d'un projet spécifique
%-build:
	@$(MAKE) -C $(subst -build,,$@)

%-clean:
	@$(MAKE) -C $(subst -clean,,$@) clean

%-fclean:
	@$(MAKE) -C $(subst -fclean,,$@) fclean

%-re:
	@$(MAKE) -C $(subst -re,,$@) re

%-test:
	@$(MAKE) -C $(subst -test,,$@) diff

# Aide
help:
	@echo "$(BLUE)Dr_Quine Makefile Help:$(RESET)"
	@echo "  $(GREEN)all$(RESET)           - Compile all projects"
	@echo "  $(GREEN)test$(RESET)          - Run tests for all projects"
	@echo "  $(GREEN)clean$(RESET)         - Clean all projects"
	@echo "  $(GREEN)fclean$(RESET)        - Full clean all projects"
	@echo "  $(GREEN)re$(RESET)            - Recompile all projects"
	@echo ""
	@echo "$(BLUE)Individual project commands:$(RESET)"
	@echo "  $(GREEN)colleen$(RESET)       - Compile Colleen"
	@echo "  $(GREEN)grace$(RESET)         - Compile Grace"
	@echo "  $(GREEN)sully$(RESET)         - Compile Sully"
	@echo ""
	@echo "$(BLUE)Project-specific commands:$(RESET)"
	@echo "  $(GREEN)<project>-build$(RESET)  - Build specific project"
	@echo "  $(GREEN)<project>-test$(RESET)   - Test specific project"
	@echo "  $(GREEN)<project>-clean$(RESET)  - Clean specific project"
	@echo "  $(GREEN)<project>-fclean$(RESET) - Full clean specific project"
	@echo "  $(GREEN)<project>-re$(RESET)     - Recompile specific project"

.PHONY: all clean fclean re test help colleen grace sully test-colleen test-grace test-sully
