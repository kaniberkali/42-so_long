NAME = library/mlx/libmlx.a
CC = gcc -Wall -Wextra -Werror
PRINT = library/ft_printf/libftprintf.a
LINE = library/get_next_line/get_next_line.a
LIBFT = library/libft/libft.a
MINILIB = library/mlx
F_LINE = library/get_next_line
F_PRINT = library/ft_printf
F_LIBFT = library/libft
LFLAGS = -framework OpenGL -framework AppKit
SO_LONG = so_long
SRCS = game/*.c

all: $(NAME) $(SO_LONG)

$(SO_LONG) : $(PRINT) $(LINE) $(LIBFT) $(SRCS)
	$(CC) $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LINE) $(LIBFT) $(SRCS) -o $(SO_LONG)
	@echo "FINISH"

$(NAME): $(MINILIB)
	make -C $(MINILIB)
	@echo "\nMLX Done!!"

$(PRINT): $(F_PRINT)
	make -C $(F_PRINT)
	@echo "\nPrintf Done!!"

$(LINE): $(F_LINE)
	make -C $(F_LINE)
	@echo "\nGet_Next_Line Done!!"

$(LIBFT): $(F_LIBFT)
	make -C $(F_LIBFT)
	@echo "\nLibft Done!!"

norm:
	norminette library/ft_printf library/get_next_line library/libft game

clean:
	make clean -C $(F_LINE)
	make clean -C $(F_LIBFT)
	make clean -C $(F_PRINT)
	make clean -C $(MINILIB)

fclean: clean
	make fclean -C $(F_LINE)
	make fclean -C $(F_LIBFT)
	make fclean -C $(F_PRINT)
	rm -rf so_long *.a

re: fclean all

.PHONY: clean re fclean all