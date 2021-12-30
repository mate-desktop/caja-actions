/*
 * Caja-Actions
 * A Caja extension which offers configurable context menu actions.
 *
 * Copyright (C) 2005 The GNOME Foundation
 * Copyright (C) 2006-2008 Frederic Ruaudel and others (see AUTHORS)
 * Copyright (C) 2009-2012 Pierre Wieser and others (see AUTHORS)
 *
 * Caja-Actions is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General  Public  License  as
 * published by the Free Software Foundation; either  version  2  of
 * the License, or (at your option) any later version.
 *
 * Caja-Actions is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even  the  implied  warranty  of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See  the  GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public  License
 * along with Caja-Actions; see the file  COPYING.  If  not,  see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Frederic Ruaudel <grumz@grumz.net>
 *   Rodrigo Moya <rodrigo@mate-db.org>
 *   Pierre Wieser <pwieser@trychlos.org>
 *   ... and many others (see AUTHORS)
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib-object.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <stdlib.h>

static const gchar *uris[] = {
		"http://robert:azerty01@mon.domain.com/path/to/a/document?query#anchor",
		"ssh://pwi.dyndns.biz:2207",
		"sftp://kde.org:1234/pub/kde",
		"/usr/bin/caja-actions-config-tool",
		"file:///home/pierre/data/eclipse/caja-actions/AUTHORS",
		NULL
};

int
main (int argc, char** argv)
{
	gchar  *scheme = NULL;
	gchar  *userinfo = NULL;
	gchar  *host = NULL;
	gchar  *path = NULL;
	gint    port;
	const gchar **uri = uris;

	g_printf ("URIs parsing test.\n\n");

	while (*uri != NULL) {
		g_uri_split (*uri,
		             G_URI_FLAGS_NONE,
		             &scheme,
		             &userinfo,
		             &host,
		             &port,
		             &path,
		             NULL,  /* query */
		             NULL,  /* fragment */
		             NULL); /* error */

		g_printf ("original  uri=%s\n", *uri);
		g_printf ("vfs      path=%s\n", path);
		g_printf ("vfs    scheme=%s\n", scheme);
		g_printf ("vfs host_name=%s\n", host);
		g_printf ("vfs host_port=%d\n", port);
		g_printf ("vfs user_info=%s\n", userinfo);
		g_printf ("\n");

		g_clear_pointer (&scheme, g_free);
		g_clear_pointer (&userinfo, g_free);
		g_clear_pointer (&host, g_free);
		g_clear_pointer (&path, g_free);

		uri++;
	}

	return EXIT_SUCCESS;
}
