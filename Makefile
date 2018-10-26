.PHONY: clean All

All:
	@echo "----------Building project:[ MinHeap - Debug ]----------"
	@cd "MinHeap" && "$(MAKE)" -f  "MinHeap.mk"
clean:
	@echo "----------Cleaning project:[ MinHeap - Debug ]----------"
	@cd "MinHeap" && "$(MAKE)" -f  "MinHeap.mk" clean
