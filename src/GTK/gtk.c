 #include<stdio.h>
 #include<stdlib.h>
 #include <gtk/gtk.h>

 void recuperation(GtkWidget *object, gpointer user_data)
 {
     //juste un petit bout de code pour recuperer l'affichage
     int i;
    const char * champtexte;
    char res[128]="";
    char q[150]="Tu attends quoi ?";
    extern GtkBuilder *builder;
    //Les diff�rents champs de ma fenetre
    GtkEntry *entry1= NULL;
    GtkLabel *label1=NULL;
    entry1= GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    label1= GTK_LABEL(gtk_builder_get_object(builder,"label1"));

    //conceptioon
    champtexte=gtk_entry_get_text(entry1);
    sprintf(res,champtexte);
    //delire
    /*if(strcmp(champtexte,q)==0)
    {

    }*/
    gtk_label_set_text(label1,champtexte);
 }

 GtkBuilder *builder = NULL;
    int
    main(int argc, char *argv [])
    {

      GtkWidget *fenetre_principale = NULL;
      GError *error = NULL;
      gchar *filename = NULL;
      GtkButton *rechercher= NULL;
      gtk_init(&argc, &argv);

      /* Ouverture du fichier Glade de la fen�tre principale */
      builder = gtk_builder_new();

      /* Cr�ation du chemin complet pour acc�der au fichier test.glade. */
      /* g_build_filename(); construit le chemin complet en fonction du syst�me */
      /* d'exploitation. ( / pour Linux et \ pour Windows) */
      filename =  g_build_filename ("fenetre.glade", NULL);
          /* Chargement du fichier glade.glade. */
      gtk_builder_add_from_file (builder, filename, &error);

      gtk_builder_connect_signals( builder, NULL);

      g_free (filename);

      //gestion de l'erreur


      if (error)
      {
        gint code = error->code;
        g_printerr("%s\n", error->message);
        //gtk_print("On entre dans l'erreur");

        g_error_free (error);
        return code;
      }

        /* R�cup�ration du pointeur de la fen�tre principale */

      fenetre_principale = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));//si c'est �a on aurra plus qu'a tester
      //autre signaux

      rechercher = GTK_BUTTON(gtk_builder_get_object(builder,"Rechercher"));
        //printf("On continue");
      /* Affectation du signal "destroy" � la fonction gtk_main_quit(); pour la fermeture de la fen�tre. */
      g_signal_connect (G_OBJECT (fenetre_principale), "destroy", (GCallback)gtk_main_quit, NULL);

      //un test pour voir si on arrive bien � recuperer les signaux d�finis dans le fichiers
      g_signal_connect(G_OBJECT(rechercher),"clicked",G_CALLBACK(recuperation),NULL);

      /* Affichage de la fen�tre principale. */

      gtk_widget_show_all (fenetre_principale);

      gtk_main();

      return 0;
    }
