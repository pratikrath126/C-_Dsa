.PHONY: clean All

All:
	@echo "----------Building project:[ polynomial_linkedlist - Debug ]----------"
	@cd "polynomial_linkedlist" && "$(MAKE)" -f  "polynomial_linkedlist.mk"
clean:
	@echo "----------Cleaning project:[ polynomial_linkedlist - Debug ]----------"
	@cd "polynomial_linkedlist" && "$(MAKE)" -f  "polynomial_linkedlist.mk" clean
