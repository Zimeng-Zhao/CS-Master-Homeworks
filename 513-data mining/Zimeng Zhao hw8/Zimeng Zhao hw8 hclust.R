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

#hclust method
#remove the first column
cancer <- cancer[-1]
#calculate the distance matrix between the observations in the dataset
cancerdist <- dist(cancer[,-1])
hclustres <- hclust(cancerdist)
plot(hclustres)
#uses the cutree() function to cut the dendrogram into two clusters based on a specific height. In this case, the height chosen is 2, which means that the dendrogram will be cut such that there are two distinct clusters.
hclust2 <- cutree(hclustres,2)
table(hclust2, cancer[,1])