
default:
	$(MAKE) -C simanneal-hill-src
	$(MAKE) -C greedy-search-src
	$(MAKE) -C branch-search-src

clean:
	$(MAKE) -C simanneal-hill-src clean
	$(MAKE) -C greedy-search-src clean
	$(MAKE) -C branch-search-src clean
	


	


