NAME = try_catch

SRCS = 	Form.cpp					\
		Bureaucrat.cpp				\
		main.cpp					\
		PresidentialPardonForm.cpp	\
		RobotomyRequestForm.cpp		\
		ShrubberyCreationForm.cpp	\
		Intern.cpp					\

OBJDIR = objs
OBJCS = $(SRCS:%.cpp=$(OBJDIR)/%.o)


CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJDIR): 
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) 
	clear
	@echo "Your Program is ready to launch"

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	@if ls *_shrubbery 1> /dev/null 2>&1; then \
		rm -f *_shrubbery; \
	fi

re: fclean all

.PHONY: all clean fclean re