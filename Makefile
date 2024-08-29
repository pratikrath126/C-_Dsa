.PHONY: clean All

All:
	@echo "----------Building project:[ infix_to_prefix - Debug ]----------"
	@cd "infix_to_prefix" && "$(MAKE)" -f  "infix_to_prefix.mk"
clean:
	@echo "----------Cleaning project:[ infix_to_prefix - Debug ]----------"
	@cd "infix_to_prefix" && "$(MAKE)" -f  "infix_to_prefix.mk" clean
