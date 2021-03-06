/*
 * null.c - the nop idle governor
 * Copyright (C) 2015 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/cpuidle.h>
#include <linux/module.h>

static int null_enable_device(struct cpuidle_driver *drv,
			      struct cpuidle_device *dev)
{
	return 0;
}

static int null_select(struct cpuidle_driver *drv, struct cpuidle_device *dev)
{
	return CPUIDLE_DRIVER_STATE_START;
}

static struct cpuidle_governor null_governor = {
	.name =		"null",
	.rating =	5,
	.enable =	null_enable_device,
	.select =	null_select,
	.owner =	THIS_MODULE,
};

/**
 * init_null - initializes the governor
 */
static int __init init_null(void)
{
	return cpuidle_register_governor(&null_governor);
}

postcore_initcall(init_null);
