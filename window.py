import mcising 
import tkinter as tk
from tkinter import ttk
import numpy as np
from PIL import Image, ImageTk

class Window():
    def __init__(self, lattice_size: tuple, num_update_sweeps: int, temperature: float, interaction: float):
        self.img = ""
        self.lattice = mcising.IsingLattice(lattice_size[0], lattice_size[1])
        self.num_update_sweeps = num_update_sweeps
        self.temperature = temperature
        self.interaction = interaction

    def run(self):
        backcolor =  "#9cc1dc"
        colorrest = "#245d86"
        root = tk.Tk()
        root.geometry("430x430")
        root.resizable(False, False)
        root.title("Ising Simulator")
        root.configure(background=backcolor)

        title = ttk.Label(
            root,
            text="2D Ising Monte Carlo Simulator",
            font=("Helvetica", 12),
            background=backcolor
            )
        title.pack(ipadx=10, ipady=10)
        self.canvas = tk.Canvas(root,width=400,height=300, background=colorrest)
        self.canvas.pack()
        slidelabel = tk.Label(text="Phase Transition Parameter:", background=backcolor, font=("Helvetica", 12))
        slidelabel.pack(ipadx=10, ipady=10)
        self.slider = ttk.Scale(root, from_=0.0, to=1.0, orient=tk.HORIZONTAL, length=300)
        self.slider.pack()

        self.update_lattice()

        root.mainloop()
    
    def update_lattice(self):
        self.canvas.delete(self.img)
        self.temperature = 4*(1 - 0.995*self.slider.get())
        mcising.run_sweeps(self.lattice, self.temperature, self.interaction, self.num_update_sweeps)
        temp = np.array(self.lattice)
        self.img = Image.fromarray(255*((temp + 1) / 2))
        self.img = self.img.resize((360,270), Image.ANTIALIAS)
        self.img = ImageTk.PhotoImage(image=self.img)
        self.canvas.create_image(400/2, 300/2, image=self.img)
        self.canvas.after(100, self.update_lattice)