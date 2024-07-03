/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:22:19 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 19:47:31 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_BONUS_H
# define SYSTEM_BONUS_H

// Window Utils

# define WIN_X 1920	
# define WIN_Y 1080
# define MNU_MRGN 300
# define TITLE "FdF - moztop"

// Keys

# define ESCAPE	53
# define ARR_LEFT 123
# define ARR_RGHT 124
# define ARR_DOWN 125
# define ARR_UP 126

// File Utils

# define FILE_EXT ".fdf"

// Error Messages

# define ERR_ARG "\e[0;32mArgument structure is: ./fdf [./fdf::FILE]\e[0m"
# define ERR_FILE "\e[0;33mFiletype could not recognized!\e[0m"
# define ERR_FNL "\e[0;33mFilename must be at least 4 characters.\e[0m"
# define ERR_OPEN "\e[0;31mAn error occured while opening file.\e[0m"
# define ERR_READ "\e[0;31mAn error occured while reading file.\e[0m"
# define ERR_CONTENT "\e[0;31mFile content is invalid, lines do not match!\e[0m"
# define ERR_MLXINIT "\e[0;31mAn error occurred during mlx initialization.\e[0m"

// System Messages

# define MSG_LOADING "\e[0;33mLoading current map, please wait...\e[0m"
# define MSG_LOADED "\e[0;32mMap loaded successfully, launching...\e[0m"

#endif