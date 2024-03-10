.DEFAULT_GOAL := usage

# user and repo
USER        = $$(whoami)
CURRENT_DIR = $(notdir $(shell pwd))

# terminal colours
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
NC      = \033[0m

data/australian-postcodes.csv:
	bin/makefile/fetch-gist.rb \
		https://gist.github.com/randomecho/5020859 | \
		bin/makefile/extract-sql-values.rb > \
		data/australian-postcodes.csv

.PHONY: install
install: data/australian-postcodes.csv
	bundle

.PHONY: rubocop-fix
rubocop-fix:
	bundle exec rubocop -A

.PHONY: rubocop
rubocop:
	bundle exec rubocop

.PHONY: rspec
rspec:
	bundle exec rspec

.PHONY: demo
demo:
	@echo "launching at Melbourne Airport 🛫"
	@echo "the ballonn 🎈 landing prediction for NOW is"
	bin/spike-predicted_lat_long.rb -37.6697 144.831 | \
		xargs bin/spike-closest_lat_long_postcode.rb
	bin/spike-fetch-screenshot.rb

.PHONY: build
build: rspec demo

.PHONY: clean
clean:
	rm data/australian-postcodes.csv

.PHONY: usage
usage:
	@echo
	@echo "Hi ${GREEN}${USER}!${NC} Welcome to ${RED}${CURRENT_DIR}${NC}"
	@echo
	@echo "Getting started"
	@echo
	@echo "${YELLOW}make${NC}              install, test and run the demo"
	@echo "${YELLOW}make build${NC}        test and run the demo"
	@echo "${YELLOW}make usage${NC}        this menu"
	@echo
	@echo "Development"
	@echo
	@echo "${YELLOW}make rubocop${NC}      rubocop"
	@echo "${YELLOW}make rubocop-fix${NC}  rubocop fix"
	@echo "${YELLOW}make rspec${NC}        rubocop fix"
	@echo
