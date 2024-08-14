.PHONY: clean All

All:
	@echo "----------Building project:[ insert_linkedlist - Debug ]----------"
	@cd "insert_linkedlist" && "$(MAKE)" -f  "insert_linkedlist.mk"
clean:
	@echo "----------Cleaning project:[ insert_linkedlist - Debug ]----------"
	@cd "insert_linkedlist" && "$(MAKE)" -f  "insert_linkedlist.mk" clean
