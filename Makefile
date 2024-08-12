.PHONY: clean All

All:
	@echo "----------Building project:[ linked_list - Debug ]----------"
	@cd "linked_list" && "$(MAKE)" -f  "linked_list.mk"
clean:
	@echo "----------Cleaning project:[ linked_list - Debug ]----------"
	@cd "linked_list" && "$(MAKE)" -f  "linked_list.mk" clean
