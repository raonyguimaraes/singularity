/* 
 * Copyright (c) 2017, SingularityWare, LLC. All rights reserved.
 *
 * Copyright (c) 2015-2017, Gregory M. Kurtzer. All rights reserved.
 *
 * Copyright (c) 2016-2017, The Regents of the University of California,
 * through Lawrence Berkeley National Laboratory (subject to receipt of any
 * required approvals from the U.S. Dept. of Energy).  All rights reserved.
 *                                                     
 * This software is licensed under a customized 3-clause BSD license.  Please
 * consult LICENSE file distributed with the sources of this project regarding
 * your rights to use or distribute this software. 
 *   
 * NOTICE.  This Software was developed under funding from the U.S. Department of
 * Energy and the U.S. Government consequently retains certain rights. As such,
 * the U.S. Government has been granted for itself and others acting on its
 * behalf a paid-up, nonexclusive, irrevocable, worldwide license in the Software                                                     
 * to reproduce, distribute copies to the public, prepare derivative works, and
 * perform publicly and display publicly, and to permit other to do so.                                                               
 *                                                                                                                                     
 */


#ifndef __SINGULARITY_IMAGE_H_
#define __SINGULARITY_IMAGE_H_

#define SQUASHFS    1
#define EXT3        2
#define DIRECTORY   3

struct image_object {
    char *path;
    char *name;
    char *loopdev;
    int offset;
    int fd;
    int type;
    int writable;
};

extern struct image_object singularity_image_init(char *path, int open_flags);
int singularity_image_fd(struct image_object *object);
char *singularity_image_loopdev(struct image_object *object);
char *singularity_image_name(struct image_object *object);
char *singularity_image_path(struct image_object *object);
char *singularity_image_bind(struct image_object *object);
int singularity_image_writable(struct image_object *object);
int singularity_image_type(struct image_object *object);
extern int singularity_image_mount(struct image_object *image, char *mount_point);

#define LAUNCH_STRING "#!/usr/bin/env run-singularity\n"

#endif
