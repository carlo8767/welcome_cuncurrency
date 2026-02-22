-- NEW TYPE
newtype Age = Ag Int
              deriving(Show, Eq)
age:: Age
age = Ag 35



--ENUMERATIONS TYPE
data Weather = Sunny | Raining | Cloudly | Windy

--CONSTRUCTOR
data Shape = Rectangle Double Double | Square Double | Circle Double
            deriving(Show)
area :: Shape -> Double
area (Rectangle b h) =  b * h
area (Square t) =  t ^ 2
circle (Circle c) = c * pi

--EITHER
bothValues :: Either String  -> Int
bothValuez 