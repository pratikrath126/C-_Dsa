.PHONY: clean All

All:
	@echo "----------Building project:[ doubly_linkedlist - Debug ]----------"
	@cd "doubly_linkedlist" && "$(MAKE)" -f  "doubly_linkedlist.mk"
clean:
	@echo "----------Cleaning project:[ doubly_linkedlist - Debug ]----------"
	@cd "doubly_linkedlist" && "$(MAKE)" -f  "doubly_linkedlist.mk" clean
