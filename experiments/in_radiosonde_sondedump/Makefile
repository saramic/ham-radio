.DEFAULT_GOAL := usage

# user and repo
USER        = $$(whoami)
CURRENT_DIR = $(notdir $(shell pwd))

# terminal colours
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
NC      = \033[0m

.PHONY: brew-bundle
brew-bundle:
	@brew --version && \
		brew bundle || \
		echo "${RED}\n\thomebrew not found${NC} you are on your own 😭"

dbdexter-dev-sondedump:
	git clone \
		git@github.com:dbdexter-dev/sondedump.git \
		dbdexter-dev-sondedump

.PHONY: build
build: brew-bundle dbdexter-dev-sondedump
	dbdexter-dev-sondedump/build/sondedump --version || \
		( pushd dbdexter-dev-sondedump && \
		mkdir build && \
		cd build && \
		cmake .. && \
		make && \
		popd && \
		dbdexter-dev-sondedump/build/sondedump --version ) && \
		echo "${GREEN}\n\tsondedump installed 🎉${NC}"

.PHONY: demo
demo:
	@dbdexter-dev-sondedump/build/sondedump --version && \
		echo "${GREEN}\n\tdemo coming soon ⏱️ ${NC}" || \
		echo "${RED}\n\trun ${YELLOW}make build${RED} to compile sondedump ❌${NC}"
	
.PHONY: clean
clean:
	rm -rf dbdexter-dev-sondedump

.PHONY: usage
usage:
	@echo
	@echo "Hi ${GREEN}${USER}!${NC} Welcome to ${RED}${CURRENT_DIR}${NC}"
	@echo
	@echo "Getting started"
	@echo
	@echo "${YELLOW}make build${NC}        build sondedump"
	@echo "${YELLOW}make demo${NC}         demo sondedump convert wav to data"
	@echo
	@echo "${YELLOW}make clean${NC}        remove stuff"
	@echo
