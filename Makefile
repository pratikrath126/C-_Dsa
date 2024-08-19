.PHONY: clean All

All:
	@echo "----------Building project:[ INSEERT_DELETE_REVERSE_LINKEDLIST - Debug ]----------"
	@cd "insert_linkedlist" && "$(MAKE)" -f  "INSEERT_DELETE_REVERSE_LINKEDLIST.mk"
clean:
	@echo "----------Cleaning project:[ INSEERT_DELETE_REVERSE_LINKEDLIST - Debug ]----------"
	@cd "insert_linkedlist" && "$(MAKE)" -f  "INSEERT_DELETE_REVERSE_LINKEDLIST.mk" clean
