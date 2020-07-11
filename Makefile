# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 00:44:42 by tsedigi           #+#    #+#              #
#    Updated: 2019/12/02 00:44:49 by tsedigi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	Program output
EXE_SERVER = server
EXE_CLIENT = client

#	GCC flags -Wall -Wextra $(CFLAGS) -g 
#-fsanitize=address -g
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra -Werror
ALL_CFLAGS = $(CFLAGS)

#	Library files
LIBFLAGS = -L./libft -lft

#	Extern includes
INC_LIBFT = libft/includes

#	Ojects/Sources directories
# pour les src : find src/dossier.. | grep .c$ puis suprimer les .c et mettre des \

INC_LIB = includes/lib_includes
INC_SERVER = includes/server_includes
INC_CLIENT = includes/client_includes
SRC_SERVER = src/server/build \
src/server/commands/command_add_log \
src/server/commands/command_cd \
src/server/commands/command_get\
src/server/commands/command_ls \
src/server/commands/command_mkdir \
src/server/commands/command_mode_admin \
src/server/commands/command_put \
src/server/commands/command_pwd \
src/server/commands/command_quit \
src/server/commands/command_quit_admin \
src/server/commands/command_rm \
src/server/commands/command_rooter \
src/server/commands/command_nc_put \
src/server/destructor/destroy_env \
src/server/destructor/destroy_usr_id \
src/server/display/display_new_conec \
src/server/error/display_err \
src/server/init/create_server \
src/server/read/read_all \
src/server/recept/ft_recept \
src/server/recept/wait_msg \
src/server/send/display_send \
src/server/tools/get_deep_path \
src/server/tools/check_cur_point \
src/server/tools/check_hidden_f \
src/server/usr_id/check_logs \
src/server/usr_id/create_logs \
src/server/usr_id/create_move_usr_dir \
src/server/usr_id/get_id_pwd \
src/server/usr_id/logs_check_add \
src/server/usr_id/push_back_usr \
src/server/usr_id/send_essential \
src/server/usr_id/write_crypt 
SRC_CLIENT = src/client/build \
src/client/commands/command_admin_mode \
src/client/commands/command_helper \
src/client/commands/command_local_cd \
src/client/commands/command_local_ls \
src/client/commands/command_local_mkdir \
src/client/commands/command_local_pwd \
src/client/commands/command_local_rm \
src/client/commands/command_logout \
src/client/commands/command_quit \
src/client/commands/command_rooter \
src/client/commands/command_send_cd \
src/client/commands/command_send_get \
src/client/commands/command_send_ls \
src/client/commands/command_send_mkdir \
src/client/commands/command_send_put \
src/client/commands/command_send_pwd \
src/client/commands/command_send_rm \
src/client/core/loop_send_recv \
src/client/destructor/destroy_env \
src/client/destructor/destroy_usr \
src/client/display/display_prompt \
src/client/error/display_err \
src/client/init/create_client \
src/client/proto/confirm_cmd \
src/client/read/read_all \
src/client/send/display_send \
src/client/tools/send_put_tools \
src/client/usr/get_infos_usr \
src/client/usr/logs_add \
src/client/usr/logs_check
SRC_LIBTOOLS += src/lib_tools/crypt_tools \
src/lib_tools/crypting \
src/lib_tools/ft_implode \
src/lib_tools/ft_len_tab \
src/lib_tools/ft_pwd \
src/lib_tools/ft_set_term \
src/lib_tools/ft_str_del_tab \
src/lib_tools/get_local_path \
src/lib_tools/get_rights \
src/lib_tools/get_trimed_path \
src/lib_tools/ft_atoi_l \
src/lib_tools/resolve_path
INCLUDES_SERVER += $(addprefix -iquote , $(INC_LIB))
INCLUDES_SERVER += $(addprefix -iquote , $(INC_SERVER))
INCLUDES_SERVER += $(addprefix -iquote , $(INC_LIBFT))
INCLUDES_CLIENT += $(addprefix -iquote , $(INC_LIB))
INCLUDES_CLIENT += $(addprefix -iquote , $(INC_CLIENT))
INCLUDES_CLIENT += $(addprefix -iquote , $(INC_LIBFT))
SRCS_SERVER += $(addsuffix .c, $(SRC_SERVER))
SRCS_CLIENT += $(addsuffix .c, $(SRC_CLIENT))
SRCS_SERVER += $(addsuffix .c, $(SRC_LIBTOOLS))
SRCS_CLIENT += $(addsuffix .c, $(SRC_LIBTOOLS))


#	Final OBJS
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

#	Layout
VERBOSE = true

all: header $(EXE_SERVER) $(EXE_CLIENT) footer

header:
	@echo "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] Compile\033[0m"
	@echo "\033[33m[\033[4m$(EXE_CLIENT)\033[0m\033[33m] Compile\033[0m"

footer:
	@echo "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] Finished\033[0m"
	@echo "\033[33m[\033[4m$(EXE_CLIENT)\033[0m\033[33m] Finished\033[0m"

$(EXE_CLIENT): lft $(OBJS_CLIENT)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(EXE_CLIENT)"
else
	@printf"\033[34m.\033[0m\n"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES_CLIENT) $(OBJS_CLIENT) -o $(EXE_CLIENT) -g $(LIBFLAGS)

$(EXE_SERVER): lft $(OBJS_SERVER)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(EXE_SERVER)"
else
	@printf"\033[34m.\033[0m\n"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES_SERVER) $(OBJS_SERVER) -o $(EXE_SERVER) -g $(LIBFLAGS)

%.o: %.c 
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile .\033[0m $<"
else
	@printf"\033[34m.\033[0m"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES_SERVER) $(INCLUDES_CLIENT) -c $< -o $@

clean:
	@echo -e "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] >>\033[0m \033[31mCLEAN all object files (*.o)\033[0m"
	@$(RM) $(OBJS_SERVER)
	@echo -e "\033[33m[\033[4m$(EXE_CLIENT)\033[0m\033[33m] >>\033[0m \033[31mCLEAN all object files (*.o)\033[0m"
	@$(RM) $(OBJS_CLIENT)	


fclean: clean lftclean
	@echo -e "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] >>\033[0m \033[31mFCLEAN project binary ($(EXE_SERVER))\033[0m"
	@$(RM) $(EXE_SERVER)
	@echo -e "\033[33m[\033[4m$(EXE_CLIENT)\033[0m\033[33m] >>\033[0m \033[31mFCLEAN project binary ($(EXE_CLIENT))\033[0m"
	@$(RM) $(EXE_CLIENT)	

re: fclean all

lft:
	@echo "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] >> Extern dependencies\033[0m"
	@make -C libft
	@echo "\033[33m[\033[4m$(EXE_SERVER)\033[0m\033[33m] << Extern dependencies\033[0m"

lftclean:
	make -C libft clean

lftfclean:
	make -C libft fclean

lftre:
	make -C libft re

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push
