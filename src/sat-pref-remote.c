#ifdef HAVE_CONFIG_H 
#include <build-config.h> 
#endif 
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include <time.h>

#include "sat-cfg.h"
#include "sat-pref-remote.h"

static GtkWidget *portEntry;
static GtkWidget *enableCheck;

/** Create and initialize widgets for remote tab. */
GtkWidget       *sat_pref_remote_create()
{
    GtkWidget       *vbox, *portbox;
    gchar           *text;
    
    //Use sat_cfg_get_bool(SAT_CFG_BOOL_ENABLE_REMOTE) to check state of the button
    enableCheck = gtk_check_button_new_with_label(_("Enable Remote Access  (restart required)"));
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enableCheck),
                                 sat_cfg_get_bool(SAT_CFG_BOOL_ENABLE_REMOTE));

    portEntry = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(portEntry), 20);
    
    text = sat_cfg_get_str(SAT_CFG_STR_PORT_NUMBER);
    gtk_entry_set_text(GTK_ENTRY(portEntry), text);
    g_free(text);

    portbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(portbox), FALSE);
    gtk_box_pack_start(GTK_BOX(portbox), gtk_label_new(_("Port:")), FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(portbox), portEntry, TRUE, TRUE, 0);
    //gtk_box_pack_start(GTK_BOX(portbox), portlabel, FALSE, FALSE, 0);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(vbox), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
    gtk_box_pack_start(GTK_BOX(vbox), enableCheck, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), portbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), gtk_separator_new(GTK_ORIENTATION_HORIZONTAL), FALSE, FALSE, 0);

    return vbox;

}

void sat_pref_remote_cancel() {

}

void sat_pref_remote_ok() {
    sat_cfg_set_bool(SAT_CFG_BOOL_ENABLE_REMOTE, gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enableCheck)));
    sat_cfg_set_str(SAT_CFG_STR_PORT_NUMBER, gtk_entry_get_text(GTK_ENTRY(portEntry)));   
}
