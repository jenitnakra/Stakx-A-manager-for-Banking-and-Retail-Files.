#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "validation.h"
char *loc;
char *username;
#include "compress.h"

  char *entry_text1;
  char *entry_text2;
  char *entry_text3;
  char *entry_text4;
  char *entry_text6;

  GtkWidget *entry1;
  GtkWidget *entry2; 
  GtkWidget *entry3;
  GtkWidget *entry4; 
  GtkWidget *entry6;

  GtkWidget *entry7;  
  GtkWidget *entry8;

 void compression_start()
  {  
        GtkWidget *dialog,*window;
        dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK,      GTK_RESPONSE_OK,      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
        gtk_widget_show_all(dialog);
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),"/");
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
        gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
        if(resp == GTK_RESPONSE_OK)
                g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
				loc = (char*)gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            FILE *fp = fopen(loc,"r");
            cmp_decmp(0,fp);
 }
 void decompression_start()
{   
        GtkWidget *dialog,*window;
        dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK,   GTK_RESPONSE_OK,      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
        gtk_widget_show_all(dialog);
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),"/");
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
        gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
        if(resp == GTK_RESPONSE_OK)
                g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
				loc =(char*) gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        FILE *fp = fopen(loc,"r");
        cmp_decmp(1,fp);
        fclose(fp);
} 

void btn1_clicked(GtkWidget *widget, gpointer data)
{
  GtkWidget *window5;
  GtkWidget *lbl1;
  GtkWidget *align1;
  GtkWidget *fixed;

                  entry_text1 = (char *) gtk_entry_get_text (GTK_ENTRY (entry1));
                  entry_text2 = (char *) gtk_entry_get_text (GTK_ENTRY (entry2));
                  entry_text3 = (char *) gtk_entry_get_text (GTK_ENTRY (entry3));
                  entry_text4 = (char *) gtk_entry_get_text (GTK_ENTRY (entry4));
                  entry_text6 = (char *) gtk_entry_get_text (GTK_ENTRY (entry6));

if(((check1(entry_text1)==1) && (strlen(entry_text1)!=0) && (check1(entry_text2)==1) && (strlen(entry_text2)!=0) && 
  (check2(entry_text3)==1)&&(strlen(entry_text3)!=0) && (check(entry_text4)==1) && (strlen(entry_text4)!=0) && 
  (check(entry_text6)==1) && (strlen(entry_text1)!=0) &&( strcmp(entry_text4,entry_text6)==0)))
{     
/////////////////////////////code for file//////////////////////////
FILE *fp;
fp = fopen("file.txt","a+");
fprintf(fp,"%s %s %s %s %s\n",entry_text1,entry_text2,entry_text3,entry_text4,entry_text6);
fclose(fp);

////////////////////////////////////////////////////////////////////

  window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window5), "Registerd");
  gtk_window_set_default_size(GTK_WINDOW(window5), 300, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window5), 15);
  gtk_window_set_position(GTK_WINDOW(window5), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window5), fixed);

  align1= gtk_alignment_new(0, 0, 0, 1);
  lbl1 = gtk_label_new("THANKU FOR CREATING ACCOUNT");

  gtk_fixed_put(GTK_FIXED(fixed), lbl1, 8,20);
  gtk_widget_set_size_request(lbl1, 300, 80);
  gtk_container_add(GTK_CONTAINER(align1), lbl1);
  gtk_container_add(GTK_CONTAINER(window5), align1);

  gtk_widget_show_all(window5);
  gtk_main();
    }
else
{
    GtkWidget *window5;

  GtkWidget *table1;

  GtkWidget *lbl1;
  GtkWidget *lbl2;
  GtkWidget *lbl3;
  GtkWidget *lbl4;
  GtkWidget *lbl5;


  window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window5), "Problem occured");
  gtk_window_set_default_size(GTK_WINDOW(window5), 200, 150);
  gtk_window_set_position(GTK_WINDOW(window5), GTK_WIN_POS_CENTER);

  table1 = gtk_table_new(3, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window5), table1);


  lbl1 = gtk_label_new("1.field cannot be empty.");
  lbl2 = gtk_label_new("2.password and username length must be 6 or more.");
  lbl3 = gtk_label_new("3.firstname and lastname must be alphabet.");
  lbl4 = gtk_label_new("4.password must contain alphabet,number,special symbol.");
  lbl5 = gtk_label_new("5.username must contai alphabet and number.");

  gtk_table_attach(GTK_TABLE(table1), lbl1, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl2, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl3, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl4, 0, 1, 3, 4, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl5 , 0, 1, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  gtk_widget_show_all(window5);
  gtk_main();
}
}
void on_btn3_clicked(GtkWidget *widget, gpointer data) 
{
/////////////////////////////////////////////////////////////////////////////////////////////////////
   username = (char *) gtk_entry_get_text (GTK_ENTRY (entry7));
   char *password = (char *) gtk_entry_get_text (GTK_ENTRY (entry8));
   char *temp[25],*rusr[15],*rpass[15];
  printf("%s",username);
 FILE *fp = fopen("file.txt","r");
 char check ;
 int lc = 0;
 int login =0;
	for (check = getc(fp); check != EOF; check = getc(fp))
        if (check == '\n') // Increment count if this character is newline
            lc = lc + 1;
 fclose(fp);
 fp = fopen("file.txt","r");
 for(int i=0;i<lc;i++){
	fscanf(fp,"%s %s %s %s %s\n",temp,temp,rusr,temp,rpass);
	printf("%s %s\n",rusr,rpass);
	if(strcmp(username,(const char *)rusr)==0 && strcmp(password,(const char *)rpass)==0){
    	login=1;
 	}
 }
 if(login==1)
 {
        GtkWidget *window,*btn2,*btn3,*fixed;
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Banking and retail files.");
        gtk_window_set_default_size(GTK_WINDOW(window), 130, 120);
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

        fixed = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(window), fixed);


        btn2 = gtk_button_new_with_label("Compress");
        gtk_fixed_put(GTK_FIXED(fixed), btn2, 20,20);
        gtk_widget_set_size_request(btn2, 100,30);
        g_signal_connect(G_OBJECT(btn2), "clicked", 
        G_CALLBACK(compression_start), NULL);
       
        btn3 = gtk_button_new_with_label("Decompress");
        gtk_fixed_put(GTK_FIXED(fixed), btn3,20,70);
        gtk_widget_set_size_request(btn3, 100,30);
		    g_signal_connect(G_OBJECT(btn3), "clicked", 
         G_CALLBACK(decompression_start), NULL);

        gtk_widget_show_all(window);
        gtk_main();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
else if(login==0)
{
  GtkWidget *window5;
  GtkWidget *lbl1;
  GtkWidget *align1;
  GtkWidget *fixed; 

  window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window5), "Action required");
  gtk_window_set_default_size(GTK_WINDOW(window5), 300, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window5), 15);
  gtk_window_set_position(GTK_WINDOW(window5), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window5), fixed);

  align1= gtk_alignment_new(0, 0, 0, 1);
  lbl1 = gtk_label_new("Incorrect username or password");

  gtk_fixed_put(GTK_FIXED(fixed), lbl1, 8,20);
  gtk_widget_set_size_request(lbl1, 300, 80);
  gtk_container_add(GTK_CONTAINER(align1), lbl1);
  gtk_container_add(GTK_CONTAINER(window5), align1);

  gtk_widget_show_all(window5);
  gtk_main();
}
}
/*void on_btn4_clicked(GtkWidget *widget, gpointer data)
{
  GtkWidget *hbox;
  GtkWidget *vbox;
  GtkWidget *combo;
  GtkWidget *btn;
  GtkWidget *window;
  GtkWidget *entry;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Forget my password");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);

  hbox = gtk_hbox_new(FALSE, 0);
  vbox = gtk_vbox_new(FALSE, 15);

  combo = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "What is your fathers middle name?");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "What is your First pet name?");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "What is the name of your favourite teacher?");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "What is your Nickname?");

  gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);

    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);

    gtk_entry_set_text (GTK_ENTRY (entry), "Enter Answer");

  gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
  gtk_widget_show (entry); 


  btn = gtk_button_new_with_label("Retrive Password");
  gtk_box_pack_start(GTK_BOX(vbox), btn, FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), hbox);

  gtk_widget_show_all(window);

  gtk_main();
}*/
void on_btn1_clicked(GtkWidget *widget, gpointer data)
 {
  GtkWidget *window1;
  GtkWidget *lbl2;
  GtkWidget *lbl3;
  GtkWidget *table;  
 
  GtkWidget *btn3;
  GtkWidget *btn4;

  window1= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window1), "LOGIN");
  gtk_container_set_border_width(GTK_CONTAINER(window1), 10);

  table = gtk_table_new(3, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window1), table);

  lbl2 = gtk_label_new("Username");
  lbl3 = gtk_label_new("Password");
  btn3= gtk_button_new_with_label("Submit");

  gtk_table_attach(GTK_TABLE(table), lbl2, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lbl3, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), btn3, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  entry7 = gtk_entry_new();
  entry8 = gtk_entry_new();
  //btn4= gtk_button_new_with_label("Forget password?");

  gtk_table_attach(GTK_TABLE(table), entry7, 1, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry8, 1, 2, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  //gtk_table_attach(GTK_TABLE(table), btn4, 1, 2, 2, 3, 
      //GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  //g_signal_connect(G_OBJECT(btn4), "clicked", 
  //G_CALLBACK(on_btn4_clicked), NULL);

 g_signal_connect(G_OBJECT(btn3), "clicked", 
  G_CALLBACK(on_btn3_clicked), NULL);

  gtk_widget_show_all(window1);
  gtk_main();
}
 void on_btn2_clicked(GtkWidget *widget, gpointer data) 
{
  GtkWidget *window2;
  GtkWidget *table1;

  GtkWidget *lbl1;
  GtkWidget *lbl2;
  GtkWidget *lbl3;
  GtkWidget *lbl4;
  GtkWidget *lbl6;
  GtkWidget *btn1;
 
  window2= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window2), "Sign Up");
  gtk_container_set_border_width(GTK_CONTAINER(window2), 10);

  table1= gtk_table_new(3, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window2), table1);

  lbl1 = gtk_label_new("FirstName");
  lbl2 = gtk_label_new("LastName");
  lbl3 = gtk_label_new("UserName");
  lbl4 = gtk_label_new("Password");
  lbl6 = gtk_label_new("Confirm Password");
  btn1 = gtk_button_new_with_label("Submit");

  gtk_table_attach(GTK_TABLE(table1), lbl1, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl2, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl3, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl4, 0, 1, 3, 4, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), lbl6 , 0, 1, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), btn1 , 0, 1, 5, 6, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);     
 
  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  entry4 = gtk_entry_new(); 
  entry6 = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table1), entry1, 1, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), entry2, 1, 2, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), entry3, 1, 2, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), entry4, 1, 2, 3, 4, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table1), entry6, 1, 2, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  

      		  g_signal_connect(G_OBJECT(btn1), "clicked", 
                  G_CALLBACK(btn1_clicked), NULL);
 
                  gtk_widget_show_all(window2);
                  gtk_main();
}
int main(int argc, char *argv[])
 {
  GtkWidget *window;
  GtkWidget *fixed;

  GtkWidget *btn1;
  GtkWidget *btn2;

  GtkWidget *align;
  GtkWidget *lbl;

  GtkWidget *align1;
  GtkWidget *lbl1;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "StakX");
  gtk_window_set_default_size(GTK_WINDOW(window), 330, 300);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);

  btn1 = gtk_button_new_with_label("Login");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 80,180);
  gtk_widget_set_size_request(btn1, 80, 30);
  g_signal_connect(G_OBJECT(btn1), "clicked", 
  G_CALLBACK(on_btn1_clicked), NULL);

  btn2 = gtk_button_new_with_label("Sign Up");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 160,180);
  gtk_widget_set_size_request(btn2, 80, 30);
  g_signal_connect(G_OBJECT(btn2), "clicked", 
  G_CALLBACK(on_btn2_clicked), NULL);

  align = gtk_alignment_new(0, 0, 0, 1);
  lbl = gtk_label_new("StakX:-");
  gtk_fixed_put(GTK_FIXED(fixed), lbl, 8,20);
  gtk_widget_set_size_request(lbl, 80, 80);
  gtk_container_add(GTK_CONTAINER(align), lbl);
  gtk_container_add(GTK_CONTAINER(window), align);
  g_signal_connect(G_OBJECT(window), "destroy", 
  G_CALLBACK(gtk_main_quit), NULL);

  align1 = gtk_alignment_new(0, 0, 0, 1);
  lbl1= gtk_label_new("A manager For banking and retail files.");
  gtk_fixed_put(GTK_FIXED(fixed), lbl1, 50,50);
  gtk_widget_set_size_request(lbl1, 300,60);
  gtk_container_add(GTK_CONTAINER(align1), lbl1);
  gtk_container_add(GTK_CONTAINER(window), align1);
  g_signal_connect(G_OBJECT(window), "destroy", 
  G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
