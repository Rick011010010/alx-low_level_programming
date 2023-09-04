#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @file_name: text file being read
 * @num_letters: number of letters to be read
 * Return: bytes_written - actual number of bytes read and printed
 *         0 when function fails or file_name is NULL.
 */
ssize_t read_textfile(const char *file_name, size_t num_letters)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_read;
    ssize_t bytes_written;

    file_descriptor = open(file_name, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * num_letters);
    if (buffer == NULL)
    {
        close(file_descriptor);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, num_letters);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);

    return (bytes_written);
}
