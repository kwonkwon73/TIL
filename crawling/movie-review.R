Sys.setlocale("LC_COLLATE", "ko_KR.UTF-8")

setwd("/Users/Kwonkwon/TIL/crawling")


library("rvest")

url_base <- 'http://movie.daum.net/moviedb/grade?movieId=110929&type=netizen&page='

all.reviews <- c()
for(page in 1:20){
	url <- paste(url_base, page, sep='', encoding='utf-8')
	htxt <- read_html(url)
	table <- html_nodes(htxt, '.list_review')
	content <- html_nodes(table, '.review_info')
	reviews <- html_text(content)
	
	if(length(reviews) == 0){break}
	all.reviews <-c(all.reviews, reviews)
	print(page)
}

write.table(all.reviews, 'movie-review.txt')