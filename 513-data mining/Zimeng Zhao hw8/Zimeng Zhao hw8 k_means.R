#  First Name : Zimeng
#  Last Name  : Zhao
#  Id			    : 20012231
#  Date       : 04/25/2023
#################################################

rm(list=ls())

#load the data
file_name <- file.choose()
cancer<- read.csv(file_name, na.strings="?")
View(cancer)

#deleting the rows with missing values
cancer <- na.omit(cancer)
summary(cancer)
table(cancer$diagnosis)

#kmeans method
#remove the first column
cancer <- cancer[-1]
cancerdist <- dist(cancer[,-1])
kmeanss <- kmeans(cancer[,-1],2,nstart = 10)
kmeanss$cluster
table(kmeanss$cluster,cancer[,1])