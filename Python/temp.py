from tkinter import *
from tkinter import filedialog as fd

root=Tk()
program_name = "IronPad"
root.title(program_name)


line_no_bar=Text(root,background='khaki',width=3)
line_no_bar.pack(side=LEFT,fill=Y,pady=2,ipady=3)


text_area=Text(root,undo=1,wrap=WORD)
text_area.pack(side=LEFT,fill=BOTH,padx=2,pady=2,ipadx=20,ipady=3,expand=YES)

#functions

def cut(event=None):
    text_area.event_generate("<<Cut>>")
    return

def copy(event=None):
    text_area.event_generate("<<Copy>>")
    return

def paste(event=None):
    text_area.event_generate("<<Paste>>")
    return

def undo(event=None):
    text_area.event_generate("<<Undo>>")
    return

def redo(event=None):
    text_area.event_generate("<<Redo>>")
    return


def save(event=None):
    name=fd.asksaveasfilename()

    text=text_area.get('1.0','end')
    myfile=open(name,'w')
    myfile.write(text)

    return

def openit(event=None):

    name= fd.askopenfilename()
    myfile=open(name,'r')
    text=myfile.read()
    text_area.insert('1.0',text)
    return


text_area.bind("<Control-y>",redo)
text_area.bind("<Control-Y>",redo)


menu_bar=Menu(root)

file_menu=Menu(menu_bar,tearoff=0)
file_menu.add_command(label="New",accelerator="Ctrl+N")
file_menu.add_command(label="Open",accelerator="Ctrl+O",command=openit)
file_menu.add_command(label="Save",accelerator="Ctrl+S",command=save)


edit_menu=Menu(menu_bar,tearoff=0)
edit_menu.add_command(label="Undo",accelerator="Ctrl+Z",command=undo)
edit_menu.add_command(label="Redo",accelerator="Ctrl+Y",command=redo)
edit_menu.add_command(label="Cut",accelerator="Ctrl+X",command=cut)
edit_menu.add_command(label="Copy",accelerator="Ctrl+C",command=copy)
edit_menu.add_command(label="Paste",accelerator="Ctrl+V",command=paste)


view_menu=Menu(menu_bar,tearoff=0)


about_menu=Menu(menu_bar,tearoff=0)

menu_bar.add_cascade(label="File",menu=file_menu)
menu_bar.add_cascade(label="Edit",menu=edit_menu)
menu_bar.add_cascade(label="View",menu=view_menu)
menu_bar.add_cascade(label="About",menu=about_menu)




root.config(menu=menu_bar)
root.mainloop()