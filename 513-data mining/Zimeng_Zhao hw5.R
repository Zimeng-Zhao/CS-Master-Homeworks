


#Course:CS513
#Name:Zimeng Zhao
#CWID:20012231

library(class)
library(rpart)

# clearing object environment
rm(list = ls())

# set working directory
setwd("C:\\Users\\65181\\Desktop\\513")
df = read.csv('breast-cancer-wisconsin.csv',header=TRUE, sep=",")
head(df, n=5)

# summarizing each colum
summary(df)
n <- as.numeric(as.character(df$F6))
summary(n, na.rm = TRUE)
df$F6 <- n
summary(df, na.rm = TRUE)

# check the number of rows before
nrow(df)

# delete the rows with missing value
df <- na.omit(df)

# check the number of rows after
nrow(df)

# convert labels to factor class
df$Class<- factor(df$Class , levels = c("2","4") , labels = c("Benign","Malignant"))

# check if factor class
is.factor(df$Class)

# generate train and test in the ratio 70% to 30%
df<- df[2:11]
size <- floor(0.70 * nrow(df))

# set the seed 
set.seed(123)
random <- sample(seq_len(nrow(df)), size = size)

# 70% data in train dataset
train <- df[random, ]

# 30% data in test dataset
test <- df[-random, ]

# implementing CART 
cart <- rpart(Class ~ ., data = train, method = "class")

# predicting class for test set
predicted <- predict(cart, test, type = "class")
print(length(predicted))
print(length(test$Class))

# confusion Matrix
conf_matrix <- table(predicted,test$Class)
print(conf_matrix)

# accuracy
accuracy <- function(x){sum(diag(x)/(sum(rowSums(x)))) * 100}
accuracy(conf_matrix)