.PHONY: clean All

All:
	@echo "----------Building project:[ GraphToTree - Debug ]----------"
	@cd "GraphToTree" && "$(MAKE)" -f  "GraphToTree.mk"
clean:
	@echo "----------Cleaning project:[ GraphToTree - Debug ]----------"
	@cd "GraphToTree" && "$(MAKE)" -f  "GraphToTree.mk" clean
