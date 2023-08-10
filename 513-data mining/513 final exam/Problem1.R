# Course      : CS 513B
# Name        : Zimeng Zhao
# CWID        : 20012231


rm(list=ls())
install.packages("C50")


#Load the data
filename<-file.choose()
Data<-read.csv(filename, na.strings=c("?"))
Data <- na.omit(Data)
View(Data)

#Convert Class Column to Factor
Data$Abs_cat <- factor(Data$Abs_cat, labels = c("Abs_high", "Abs_med", "Abs_low"))
View(Data$Abs_cat)
is.factor(Data$Abs_cat)

#get same data
set.seed(123)

#test data & training data
idx<-seq(1,nrow(Data),by=4)
idx
training<-Data[-idx,]
nrow(training)
test<-Data[idx,]
nrow(test)


library('C50')

#C50
C50_class <- C5.0(Abs_cat~.,data=training )
summary(C50_class )

C50_predict<-predict( C50_class ,test, type="class" )
str(C50_predict)
a<-table(actual=test$Abs_cat,C50=C50_predict)
a

#Accuracy
Accuracy <-(sum(diag(a))/(sum(rowSums(a)))*100) 
Accuracy

#Error rate
e<-100-Accuracy
e

#Precision of your classification for Abs_cat=Abs_High
Precision = a[1,1] / (a[1,1] + a[2,1])
Precision