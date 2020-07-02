import turtle

i = 0
t = turtle.Turtle()
t.shape("turtle")
count = 0

while True:
    t.fd(200)
    t.rt(90)
    t.fd(20)
    t.rt(90)
    t.fd(200)
    t.lt(90)
    t.fd(20)
    t.lt(90)

    count += 1

    if count == 5:
        break

# 우로 200
# 하로 20
# 좌로 200
# 하로 20
