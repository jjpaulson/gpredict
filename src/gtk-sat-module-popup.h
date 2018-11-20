#ifndef __GTK_SAT_MODULE_POPUP_H__
#define __GTK_SAT_MODULE_POPUP_H__ 1

void            gtk_sat_module_popup(GtkSatModule * module);
gboolean        module_window_config_cb(GtkWidget *, GdkEventConfigure *,
                                        gpointer);
void            rotctrl_cb_remote(gpointer data);
void            rigctrl_cb_remote(gpointer data);
//GtkWidget *     rot_menuitem;
//GtkWidget *     rig_menuitem;
#endif
