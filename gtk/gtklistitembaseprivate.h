/*
 * Copyright © 2023 Benjamin Otte
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Benjamin Otte <otte@gnome.org>
 */

#ifndef __GTK_LIST_ITEM_BASE_PRIVATE_H__
#define __GTK_LIST_ITEM_BASE_PRIVATE_H__

#include "gtkwidget.h"

G_BEGIN_DECLS

#define GTK_TYPE_LIST_ITEM_BASE         (gtk_list_item_base_get_type ())
#define GTK_LIST_ITEM_BASE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GTK_TYPE_LIST_ITEM_BASE, GtkListItemBase))
#define GTK_LIST_ITEM_BASE_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k), GTK_TYPE_LIST_ITEM_BASE, GtkListItemBaseClass))
#define GTK_IS_LIST_ITEM_BASE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GTK_TYPE_LIST_ITEM_BASE))
#define GTK_IS_LIST_ITEM_BASE_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GTK_TYPE_LIST_ITEM_BASE))
#define GTK_LIST_ITEM_BASE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GTK_TYPE_LIST_ITEM_BASE, GtkListItemBaseClass))

typedef struct _GtkListItemBase GtkListItemBase;
typedef struct _GtkListItemBaseClass GtkListItemBaseClass;

struct _GtkListItemBase
{
  GtkWidget parent_instance;
};

struct _GtkListItemBaseClass
{
  GtkWidgetClass parent_class;

  void                  (* update)                              (GtkListItemBase        *self,
                                                                 guint                   position,
                                                                 gpointer                item,
                                                                 gboolean                selected);
};

GType                   gtk_list_item_base_get_type             (void) G_GNUC_CONST;

void                    gtk_list_item_base_update               (GtkListItemBase        *self,
                                                                 guint                   position,
                                                                 gpointer                item,
                                                                 gboolean                selected);

guint                   gtk_list_item_base_get_position         (GtkListItemBase        *self);
gpointer                gtk_list_item_base_get_item             (GtkListItemBase        *self);
gboolean                gtk_list_item_base_get_selected         (GtkListItemBase        *self);

G_END_DECLS

#endif  /* __GTK_LIST_ITEM_BASE_PRIVATE_H__ */