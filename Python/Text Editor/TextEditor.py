from tkinter import *

root=Tk()


show_line_no=IntVar()
show_line_no.set(1)


# Creating text area
content_text=Text(root,wrap="word",undo=1)

shortcut_bar=Frame(root,background='light sea green',height=25)
shortcut_bar.pack(fill=X,expand='no')

line_no_bar=Text(root,width=2,background="khaki",padx=5,state='disabled')
line_no_bar.pack(fill=Y,side=LEFT,expand='no')




def get_line_numbers():
    output=''
    if show_line_no.get():
        row,column=content_text.index("end").split('.')
        for i in range(1,int(row)):
            output+=str(i)+'\n'

    return output

def update_line_numbers(event = None):
    line_numbers = get_line_numbers()
    line_no_bar.config(state='normal')
    line_no_bar.delete('1.0', 'end')
    line_no_bar.insert('1.0', line_numbers)
    line_no_bar.config(state='disabled')


def on_content_changed(event=None):
    update_line_numbers()


def cut():
    content_text.event_generate("<<Cut>>")
    on_content_changed()
    return

def paste():
    content_text.event_generate("<<Paste>>")
    on_content_changed()
    return

def copy():
    content_text.event_generate("<<Copy>>")
    on_content_changed()
    return

def undo():
    content_text.event_generate("<<Undo>>")
    on_content_changed()
    return

def redo(event=None):
    content_text.event_generate("<<Redo>>")
    on_content_changed()
    return 'break'

def select_all(event=None):
    content_text.tag_add('sel','1.0','end')
    return 'break'




content_text.bind("<Control-y>",redo)
content_text.bind("<Control-Y>",redo)
content_text.bind("<Control-a>",select_all)
content_text.bind("<Control-A>",select_all)
content_text.bind("<Any-KeyPress>",on_content_changed)
scroll_bar=Scrollbar(content_text);
content_text.configure(yscrollcommand=scroll_bar.set)
scroll_bar.config(command=content_text.yview)

#End of text area creation and scroll bar is also added using above code

#Defining name of program
program_name="Notepad--"
root.title(program_name)

#End of name definition





menu_bar=Menu(root)

file_menu=Menu(menu_bar,tearoff=0)
file_menu.add_command(label="New",accelerator="Ctrl+N")

edit_menu=Menu(menu_bar,tearoff=0)
edit_menu.add_command(label="Undo",accelerator="Ctrl+Z",command=undo)
edit_menu.add_command(label="Redo",accelerator="Ctrl+Y",command=redo)
edit_menu.add_command(label="Cut",accelerator="Ctrl+X",command=cut)
edit_menu.add_command(label="Copy",accelerator="Ctrl+C",command=copy)
edit_menu.add_command(label="Paste",accelerator="Ctrl+V",command=paste)
edit_menu.add_command(label="Select All",accelerator="Ctrl+A",command=select_all)


view_menu=Menu(menu_bar,tearoff=0)
view_menu.add_checkbutton(label="Show Line Number",variable=show_line_no)




about_menu=Menu(menu_bar,tearoff=0)


menu_bar.add_cascade(label="File",menu=file_menu)
menu_bar.add_cascade(label="Edit",menu=edit_menu)
menu_bar.add_cascade(label="View",menu=view_menu)
menu_bar.add_cascade(label="About",menu=about_menu)

root.config(menu=menu_bar)




scroll_bar.pack(side=RIGHT,fill=Y)
content_text.pack(fill=BOTH,expand='yes')


#command functions

root.mainloop()
