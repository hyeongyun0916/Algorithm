package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	f, err := os.Open("input.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer f.Close()
	os.Stdin = f
	var sc = bufio.NewScanner(os.Stdin)
	const MaxBuf int = 400000
	sc.Buffer(make([]byte, 0, MaxBuf), MaxBuf)
	if sc.Scan() {
		queries := sc.Text()
		fields := strings.Fields(queries)
		for _, s := range fields {
			num, err := strconv.Atoi(s)
			if err != nil {
				fmt.Println("변환 에러:", err)
				continue
			}
			fmt.Println(num)
		}
	}
}
