-- NEW TYPE
newtype Age = Ag Int
              deriving(Show, Eq)
age:: Age
age = Ag 35



--ENUMERATIONS TYPE
data Weather =  Sunny | Raining | Cloudly | Windy
                deriving(Show)

returnWeather :: String -> Weather
returnWeather (x)| x == "Sunny" = Sunny
                 | otherwise = error "Invalid weather input"

--CONSTRUCTOR
data Shape = Rectangle Double Double | Square Double | Circle Double
            deriving(Show)
area :: Shape -> Double
area (Rectangle b h) =  b * h
area (Square t) =  t ^ 2
circle (Circle c) = c * pi

--EITHER
--bothValues :: Either String  -> Int
-- bothValuez 

-- DATA RECORD

data Student  = Student {name::String , agesSTudent::Int}
                deriving(Show )


-- ACCESSOR FUNCTION

data Studentss  = StudentAccessor {names::String , agesSTudents::Int}
                deriving(Show )

getUsernName :: Studentss -> String
getUsernName (StudentAccessor n _) = n


