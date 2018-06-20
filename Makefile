.PHONY: clean All

All:
	@echo "----------Building project:[ DFS - Debug ]----------"
	@cd "DFS" && "$(MAKE)" -f  "DFS.mk"
clean:
	@echo "----------Cleaning project:[ DFS - Debug ]----------"
	@cd "DFS" && "$(MAKE)" -f  "DFS.mk" clean
