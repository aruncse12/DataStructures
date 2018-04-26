.PHONY: clean All

All:
	@echo "----------Building project:[ ZAlgorithm - Debug ]----------"
	@cd "ZAlgorithm" && "$(MAKE)" -f  "ZAlgorithm.mk"
clean:
	@echo "----------Cleaning project:[ ZAlgorithm - Debug ]----------"
	@cd "ZAlgorithm" && "$(MAKE)" -f  "ZAlgorithm.mk" clean
