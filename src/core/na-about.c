/*
 * Caja-Actions
 * A Caja extension which offers configurable context menu actions.
 *
 * Copyright (C) 2005 The GNOME Foundation
 * Copyright (C) 2006-2008 Frederic Ruaudel and others (see AUTHORS)
 * Copyright (C) 2009-2012 Pierre Wieser and others (see AUTHORS)
 * Copyright (C) 2013-2020 Wolfgang Ulbrich (see AUTHORS)
 * Copyright (C) 2021 The MATE developers
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
 *   Wolfgang Ulbrich <mate@raveit.de>
 *   ... and many others (see AUTHORS)
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib/gi18n-lib.h>

#include "na-about.h"

/*
 * na_about_display:
 * @toplevel: the parent window.
 *
 * Displays the About dialog.
 */
void
na_about_display (GtkWindow *toplevel)
{
	gchar *license_text;

	const gchar *artists [] = {
		"Ulisse Perusin <uli.peru@gmail.com>",
		"DragonArtz - http://www.dragonartz.net/",
		NULL
	};

	const gchar *authors [] = {
		"Frederic Ruaudel <grumz@grumz.net>",
		"Rodrigo Moya <rodrigo@mate-db.org>",
		"Pierre Wieser <pwieser@trychlos.org>",
		NULL
	};

	const gchar *documenters [] = {
		NULL
	};

	const gchar *license [] = {
		N_("Caja-Actions Configuration Tool is free software; you can "
		    "redistribute it and/or modify it under the terms of the GNU General "
		    "Public License as published by the Free Software Foundation; either "
		    "version 2 of the License, or (at your option) any later version."),
		N_("Caja-Actions Configuration Tool is distributed in the hope that it "
		   "will be useful, but WITHOUT ANY WARRANTY; without even the implied "
		   "warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See "
		   "the GNU General Public License for more details."),
		N_("You should have received a copy of the GNU General Public License along "
		   "with Caja-Actions Configuration Tool ; if not, write to the Free "
		   "Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, "
		   "MA 02110-1301, USA."),
		NULL
	};

	license_text =  g_strjoin ("\n\n", _(license[0]), _(license[1]), _(license[2]), NULL);

	gtk_show_about_dialog (toplevel,
	                       "artists", artists,
	                       "authors", authors,
	                       /* i10n: "Caja actions" here is not a typo; this does not refer to the
	                        * Caja-Actions product, but to the actions which are to be added to Caja */
	                       "comments", _("A graphical interface to create and edit your Caja actions."),
	                       "copyright", _("Copyright \xc2\xa9 2009-2012 Pierre Wieser <pwieser@trychlos.org>\n"
	                                      "Copyright \xc2\xa9 2013-2020 Wolfgang Ulbrich <mate@raveit.de>\n"
	                                      "Copyright \xc2\xa9 2021 The MATE developers"),
	                       "documenters", documenters,
	                       "license", license_text,
	                       "logo-icon-name", PACKAGE,
	                       "program-name", _("Caja-Actions"),
	                       "translator-credits", _("translator-credits"),
	                       "version", PACKAGE_VERSION,
	                       "website", PACKAGE_URL,
	                       "wrap-license", TRUE,
	                       NULL);

	g_free (license_text);
}
