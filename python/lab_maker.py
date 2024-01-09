out = open("l.txt", "w")

txt = ""

templ = """v[@].W = x;
v[@].E = y;
v[@].N = z;
v[@].S = t;
v[@].dir[0] = x;
v[@].dir[1] = y;
v[@].dir[2] = z;
v[@].dir[3] = t;
"""

moves = [[0, 1, 0, 0],
         [1, 1, 0, 1],
         [1, 1, 0, 0],
         [1, 0, 0, 1],
         [0, 0, 0, 1],
         [0, 1, 0, 1],
         [1, 1, 1, 1],
         [1, 0, 0, 1],
         [0, 1, 1, 1],
         [1, 0, 1, 0],
         [0, 0, 1, 1],
         [0, 0, 1, 1],
         [0, 0, 1, 0],
         [0, 1, 1, 1],
         [1, 0, 0, 1],
         [0, 1, 1, 1],
         [1, 1, 1, 0],
         [1, 0, 0, 0],
         [0, 0, 1, 0],
         [0, 0, 1, 1],
         [0, 1, 1, 0],
         [1, 1, 0, 0],
         [1, 1, 0, 0],
         [1, 1, 0, 0],
         [1, 0, 1, 0]]

for i, mv in enumerate(moves):
    crt = templ.replace("@", str(i))
    crt = crt.replace("x", str(mv[0]))
    crt = crt.replace("y", str(mv[1]))
    crt = crt.replace("z", str(mv[2]))
    crt = crt.replace("t", str(mv[3]))
    txt = txt + crt

out.write(txt)
