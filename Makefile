.PHONY: clean All

All:
	@echo "----------Building project:[ merge_linkedlist - Debug ]----------"
	@cd "merge_linkedlist" && "$(MAKE)" -f  "merge_linkedlist.mk"
clean:
	@echo "----------Cleaning project:[ merge_linkedlist - Debug ]----------"
	@cd "merge_linkedlist" && "$(MAKE)" -f  "merge_linkedlist.mk" clean
