multiply :: Num a => a -> a -> a -> a 
multiply x y z = x * y * z 


safeMinimum2 :: Ord a => [a] -> Either String a
safeMinimum2 [] = Left "empty list"
safeMinimum2 xs = Right (minimum xs)

safeMin :: Ord a => [a] -> Maybe a 
safeMin [] = Nothing 
safeMin xs = Just (minimum xs)


tailsSum :: Num a => [a] -> a 
tailsSum xs = f xs 0 
        where
            f [] acc = acc
            f (x:xs) acc = f xs (x + acc )



-- | Write a function "ntail" that returns last n elements of a list
--
-- Examples:
--
-- >>> ntail 2 [1,2,3,4,5]
-- [4,5]
-- >>> ntail 6 "Hello World!"
-- "World!"
-- >>> ntail 0 [1.2, 4,2]
-- []
ntail :: Int -> [a] -> [a]
ntail n xs  = drop (length xs - n)xs




