.PHONY: clean All

All:
	@echo "----------Building project:[ sparse_matrix - Debug ]----------"
	@cd "sparse_matrix" && "$(MAKE)" -f  "sparse_matrix.mk"
clean:
	@echo "----------Cleaning project:[ sparse_matrix - Debug ]----------"
	@cd "sparse_matrix" && "$(MAKE)" -f  "sparse_matrix.mk" clean
