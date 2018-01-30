from tkinter import *
import pypyodbc
class Accounts:

    def open_connection(self):
        connection = pypyodbc.connect("Driver={SQL Server};Server=ZARVIS\SQLEXPRESS;Database=Accounts;uid=sa;pwd=mysql")
        return connection


    def __init__(self):
        self.ac=""
        self.name=""
        self.root=Tk()
        self.program_name="Accounts"
        self.root.title(self.program_name)

        #create menu bar
        self.menu_bar=Menu(self.root)

        self.action_menu=Menu(self.menu_bar,tearoff=0)

        self.action_menu.add_command(label="Add Customer",accelerator="Ctrl+N",command=self.add_user)
        self.action_menu.add_command(label="Show Database",command=self.show_db)
        self.action_menu.add_command(label="Delete Account",accelerator="Ctrl+D",command=self.delectac)
        self.action_menu.add_command(label="Exit",accelerator="Ctrl+E",command=self.getout)
        self.menu_bar.add_cascade(label="Actions",menu=self.action_menu)
        self.text_area=Text(self.root,width=50)
        self.text_area.pack(side=LEFT,fill=BOTH)

        self.root.config(menu=self.menu_bar)
        self.root.mainloop()

    def getout(self):
        self.root.destroy()

    def get_user_info(self):
        window = Tk()
        window.title("New Account")
        label = Label(window, text="Enter Account No : ")
        label.grid(row=5, sticky=W, padx=5, pady=15)
        entry = Entry(window)
        entry.grid(row=5, column=17, sticky=E, padx=3, pady=15)
        label1 = Label(window, text="Enter Customer Name : ")
        label1.grid(row=10, sticky=W, padx=5, pady=15)
        entry1 = Entry(window)
        entry1.grid(row=10, column=17, sticky=E, padx=3, pady=15)
        submit = Button(window, text="Submit", command=lambda: self.submit(entry.get(),entry1.get(),window))
        submit.grid(row=15, column=15, padx=5, pady=2)
        window.mainloop()

    def submit(self,a,b,window):
        self.ac=a
        self.name=b
        window.quit()
        window.destroy()
        return

    def add_user(self):
        self.get_user_info()
        con=self.open_connection()
        account_no=int(self.ac)
        user_name=str(self.name)
        Values=[account_no,user_name]
        cursor = con.cursor()
        sqlcommand = "INSERT mydb VALUES(?,?)"
        cursor.execute(sqlcommand,Values)
        con.commit()
        con.close()
        self.text_area.delete('1.0','end')
        self.text_area.insert('1.0',"OPERATION COMPLETED\n\nONE ACCOUNT ADDED SUCCESSFULLY")


    def getac(self):
        window=Tk()

        window.title("Delete Account")
        label = Label(window, text="Enter Account No : ")
        label.grid(row=5, sticky=W, padx=5, pady=15)
        entry = Entry(window)
        entry.grid(row=5, column=17, sticky=E, padx=3, pady=15)

        submit = Button(window, text="Submit", command=lambda: self.submitac(entry.get(), window))
        submit.grid(row=10, column=15, padx=5, pady=2)
        window.mainloop()

    def delectac(self):
        self.getac()
        con=self.open_connection()
        cursor=con.cursor()
        value=[self.ac]
        sqlprim="SELECT * FROM mydb WHERE account_no = (?)"
        cursor.execute(sqlprim,value)
        output=cursor.fetchone()
        self.text_area.delete('1.0', 'end')
        if output:
            sqlcommand="DELETE FROM mydb WHERE account_no = (?)"
            cursor.execute(sqlcommand,value)

            self.text_area.insert('1.0', "OPERATION COMPLETED\n\nONE ACCOUNT DELETED SUCCESSFULLY")
        else:
            self.text_area.insert('1.0',"SORRY\n\nTHIS ACCOUNT NO. DOES NOT EXIST")
        con.commit()
        con.close()


    def submitac(self, a, window):
        self.ac = a
        window.quit()
        window.destroy()
        return


    def show_db(self):
        con=self.open_connection()
        sqlcommand="SELECT * FROM mydb ORDER BY account_no"
        cursor=con.cursor()
        cursor.execute(sqlcommand)

        text_out="   Account           Name\n"
        output=cursor.fetchone()
        while output:
            text_out+="  %5s"%(output[0])+"            "+str(output[1])+"\n"
            output=cursor.fetchone()
        self.text_area.delete('1.0','end')
        self.text_area.insert('1.0',text_out)
        con.close()



myapp=Accounts()
