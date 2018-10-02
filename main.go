package main

import (
	"encoding/json"
	"fmt"
	"github.com/gorilla/mux"
	"log"
	"math/rand"
	"net/http"
	"os"
	"strconv"
)

type Book struct {
	ID     string  `json:"id"`
	Isbn   string  `json:"isbn"`
	Title  string  `json:"title"`
	Author *Author `json:"author"`
}

type Author struct {
	Firstname string `json:"firstname"`
	Lastname  string `json:"lastname"`
}

var books []Book

func getBooks(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(books)
}

func getBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r)
	for _, item := range books {
		if item.ID == params["id"] {
			json.NewEncoder(w).Encode(item)
			return
		}
	}
	json.NewEncoder(w).Encode(&Book{})

}

func createBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	var book Book
	_ = json.NewDecoder(r.Body).Decode(&book)
	book.ID = strconv.Itoa(rand.Intn(100000))
	books = append(books, book)
	json.NewEncoder(w).Encode(book)
}

func updateBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r)
	for index, item := range books {
		if item.ID == params["id"] {
			books = append(books[:index], books[index+1:]...)

			var book Book
			_ = json.NewDecoder(r.Body).Decode(&book)
			book.ID = strconv.Itoa(rand.Intn(1000000))
			books = append(books, book)
			json.NewEncoder(w).Encode(book)
			return
		}
	}
	json.NewEncoder(w).Encode(books)
}

func deleteBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r)
	for index, item := range books {
		if item.ID == params["id"] {
			books = append(books[:index], books[index+1:]...)
			break
		}
	}
	json.NewEncoder(w).Encode(books)
}

func main() {
	host := os.Args[1]
	port := os.Args[2]
	r := mux.NewRouter()

	books = append(books, Book{ID: "1", Isbn: "451313", Title: "Programming Python",
		Author: &Author{Firstname: "Mark", Lastname: "Luzt"}})
	books = append(books, Book{ID: "2", Isbn: "212313", Title: "Introduce Golang",
		Author: &Author{Firstname: "Brian", Lastname: "MacDonald"}})
	books = append(books, Book{ID: "3", Isbn: "474561", Title: "The C++ Programming Language",
		Author: &Author{Firstname: "Bjarne", Lastname: "Stroustrup"}})
	books = append(books, Book{ID: "4", Isbn: "876615", Title: "Machine Learning in Python",
		Author: &Author{Firstname: "Michael", Lastname: "Bowles"}})
	books = append(books, Book{ID: "5", Isbn: "878615", Title: "An Introduce to Statistics",
		Author: &Author{Firstname: "Keone", Lastname: "Hon"}})

	r.HandleFunc("/api/books", getBooks).Methods("GET")
	r.HandleFunc("/api/books/{id}", getBook).Methods("GET")
	r.HandleFunc("/api/books", createBook).Methods("POST")
	r.HandleFunc("/api/books/{id}", updateBook).Methods("PUT")
	r.HandleFunc("/api/books/{id}", deleteBook).Methods("DELETE")
	fmt.Println("Server running on " + host + ", port " + port + "...")
	log.Fatal(http.ListenAndServe(host+":"+port, r))
}
