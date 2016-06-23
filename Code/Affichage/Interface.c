#include <stdlib.h>
#include <gtk-2.0/gtk/gtk.h>
#include "sdl.c"
#include <libgen.h>
void OnToggle();
void Selection();
void dilate();
void grey();
int erreur();
void Chemin (GtkWidget *widget, gpointer user_data);
GtkWidget *pFilename = NULL;
SDL_Surface *img = NULL;

int main(int argc, char **argv)
{
    GtkWidget *MainWindow = NULL;
    GtkWidget *OKButton = NULL;
    GtkWidget *Diilate = NULL;
    GtkWidget *ChooseFile = NULL;
    GtkWidget *Quitter = NULL;
    GtkWidget *Grey = NULL;
    GtkWidget *pVBox = NULL;
//  GtkWidget *pFilename = NULL;
    gchar *Filename = g_locale_to_utf8("Aucun fichier pour le moment", -1, NULL, NULL, NULL);
    gtk_init(&argc, &argv);

    /* Création de la fenetre */
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(MainWindow), "OCR");

    /* Création de la box contenant les boutons */
    pVBox = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(MainWindow), pVBox);
    
    /* Création du texte filename */
    pFilename = gtk_label_new(Filename);
    g_free(Filename); //On free le bom, on en a plus besoin
    gtk_label_set_justify(GTK_LABEL(pFilename), GTK_JUSTIFY_CENTER);
    gtk_container_add(GTK_CONTAINER(pVBox), pFilename);
    
    /* Création du Bouton pour choisir un fichier */
    /*ChooseFile = gtk_file_chooser_dialog_new("Choisir un fichier", );
    gtk_box_pack_start(GTK_BOX(pVBox), ChooseFile, FALSE, FALSE, 0);*/
    ChooseFile=gtk_button_new_with_mnemonic("_Explorer ...");
    gtk_box_pack_start(GTK_BOX(pVBox), ChooseFile, FALSE, FALSE, 0);
    /* Création du bouton Quitter */
    Quitter = gtk_toggle_button_new_with_label("Quitter");

    /* Création du bouton OK*/
    OKButton = gtk_toggle_button_new_with_label("Line");
    gtk_box_pack_start(GTK_BOX(pVBox), OKButton, FALSE, FALSE, 0);
    
    /* Création du bouton Grey*/
    Grey = gtk_toggle_button_new_with_label("GreyScale");
    gtk_box_pack_start(GTK_BOX(pVBox), Grey, FALSE, FALSE, 0);

    /* Création du bouton test dilate_pixel*/
    Diilate = gtk_toggle_button_new_with_label("dilate_pixel");
    gtk_box_pack_start(GTK_BOX(pVBox), Diilate, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(pVBox), Quitter, FALSE, FALSE, 0);
    gtk_widget_show_all(MainWindow);

    /*g_signal_connect(G_OBJECT(ChooseFile), "toggled", G_CALLBACK(OnToggle), NULL);*/
    g_signal_connect(G_OBJECT(ChooseFile), "clicked", G_CALLBACK(Selection), NULL);
    g_signal_connect(G_OBJECT(OKButton), "toggled", G_CALLBACK(OnToggle), NULL);
    g_signal_connect(G_OBJECT(Diilate), "toggled", G_CALLBACK(dilate), NULL);
    g_signal_connect(G_OBJECT(Grey), "toggled", G_CALLBACK(grey), NULL);
    g_signal_connect(G_OBJECT(Quitter), "toggled", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return EXIT_SUCCESS;
}
int erreur(){
 	return img == NULL;
}
void grey(){
if(!erreur()){ grey_scale(img);}
 }
void dilate(){
if(!erreur()) { dilate_pixel(img);}
}
void OnToggle(){	
if(!erreur()) {	Line(img);}
}

void Selection()
{
    GtkWidget *pSelection;
    pSelection = gtk_file_selection_new("Selectionner un fichier");
    gtk_widget_show(pSelection);
    gtk_window_set_modal(GTK_WINDOW(pSelection), TRUE);
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(pSelection)->ok_button), "clicked", G_CALLBACK(Chemin), pSelection);
    g_signal_connect_swapped(G_OBJECT(GTK_FILE_SELECTION(pSelection)->cancel_button), "clicked", G_CALLBACK(gtk_widget_destroy), pSelection);
}

void Chemin(GtkWidget *widget, gpointer user_data)
{
	GtkWidget *file_selector = GTK_WIDGET (user_data); 
	const gchar *selected_filename; 
	selected_filename = gtk_file_selection_get_filename (GTK_FILE_SELECTION (file_selector));
	char *merde = (char*)selected_filename;
	widget = widget +1 -1;
	g_print ("Selected filename: %s\n", selected_filename);
//	char *pfile;
	char *name = merde;
	name = basename(name);
//	char *name = &merde;
	printf(" \n name is equal to %c", *name);
	img = load_image(name);
	

        gtk_widget_destroy(file_selector);
}
