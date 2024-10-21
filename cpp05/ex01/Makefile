# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp

# Object files (replace .cpp extensions with .o)
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = bureaucrat_form

# Header files
HEADERS = Bureaucrat.hpp

# Commands
RM = rm -f

# Rules
all: $(NAME)

# Link the object files to create the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile each .cpp into .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	$(RM) $(OBJS)

# Fclean rule to remove object files and the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all

# Phony rules to avoid conflicts with file names
.PHONY: all clean fclean re
