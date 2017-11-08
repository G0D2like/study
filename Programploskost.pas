program ploskost;

uses CRT, GraphABC;
var
  u, ugol, m, n, a, fd, fu, ax, ay, t, tm: real;
  h, l, x, y, x0, y0: integer;

begin
MaximizeWindow;
  read(ugol, h, m, n);
  u := (ugol * 3.14) / 180;
  t := 0;
  
  l := trunc(h * (cos(u) / sin(u)));
  x0 := 300;
  y0 := 400;
  SetPenWidth(5);
  SetPenColor(clGreen);
  line(x0, y0, x0 + l, y0 + h);
  line(x0, y0, x0, y0 + h);
  line(x0, y0 + h, x0 + l, y0 + h);
  
  fu := m * 10 * n * cos(u);
  fd := m * 10 * sin(u);
  //if fd > fu then begin
    a := (fd - fu) / m;
    ay := a * sin(u);
    ax := a * cos(u);
    tm := sqrt((2 * h) / ay);
    SetPenColor(clBlack);
    Circle(x0,y0-10,10);
    while t <= tm do
    begin
      x := x0+trunc(((ax * sqr(t)) / 2));
      y := y0+trunc(((ay * sqr(t)) / 2));
      Circle(x, y, 10);
      delay(10);
      t:=t+0.1;
    end;
  //end;
end.