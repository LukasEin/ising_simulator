from window import Window

def main():
    # do no change those numbers
    lattice_size = (210,280)
    num_update_sweeps = 30
    temperature = 5

    # this can be changed between -1 and +1
    # -1 gives a ferromagnetic phase transition
    # +1 gives an antiferromagnetic phase transition
    interaction = -1

    window = Window(lattice_size, num_update_sweeps, temperature, interaction)

    window.run()



if __name__ == "__main__":
    main()