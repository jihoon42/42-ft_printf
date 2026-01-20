# ft_printf

*This project has been created as part of the 42 curriculum by jkim2.* 

---

## 1. Description

The `ft_printf` project is a mandatory assignment in the 42 core curriculum designed to mimic the behavior of the standard C library's `printf()` function. The primary goal is to master the use of **variadic functions** in C and to implement a robust formatting logic that converts various data types into character strings. This implementation focuses on core logic without implementing the buffer management of the original function.

Supported Conversions 

* 
**%c**: Prints a single character.


* **%s**: Prints a string (handles `NULL` pointers by printing `(null)`).
* 
**%p**: Prints a `void *` pointer in hexadecimal format.


* 
**%d / %i**: Prints signed base 10 integers.


* 
**%u**: Prints unsigned base 10 numbers.


* 
**%x / %X**: Prints numbers in hexadecimal (base 16) lowercase or uppercase.


* 
**%%**: Prints a literal percent sign.



---

2. Instructions 

### Compilation

The library is compiled using a `Makefile` that follows the 42 Norm, utilizing `cc` with `-Wall -Wextra -Werror` flags. The `Makefile` is designed to prevent unnecessary relinking.

```bash
# Create the library (libftprintf.a)
make

# Remove object files and the library
make fclean

```

### Development Environment & Verification

* **Working Environment**: Developed on **macOS (Apple M1 Pro)** and cross-verified in the **42 Cluster Ubuntu** environment.
* 
**Memory Management**: Extensive checks were performed to ensure no memory leaks occur.


* **macOS**: Verified using `leaks -atExit -- ./test`.
* **Ubuntu**: Verified using `valgrind --leak-check=full ./test`.



---

3. Algorithm and Data Structure (Justification) 

### Hierarchical Modular Architecture

The project is structured into two layers: **Printers** (`/printers`) for specifier-specific logic and **Utils** (`/utils`) for low-level output.

* 
**Justification**: By isolating the logic for each conversion (e.g., `%p`, `%x`) into independent files, the system becomes highly extensible. This prevents modifications in one specifier from affecting others, facilitating easier debugging and maintenance.



### Universal Base Conversion Engine (`ft_putbase_ull`)

A generalized conversion engine was implemented to handle various bases using `unsigned long long` types.

* **Justification**: Since `%u`, `%x`, `%X`, and `%p` all involve representing numbers in different bases, a single stable engine reduces code duplication. Using a recursive approach allows for correct digit ordering without the need for manual buffer allocation, which eliminates potential memory leaks and adheres to functional programming principles.

### OS-Specific Pointer Handling

The project includes a platform-dependent macro (`NULL_PTR`) to handle pointer addresses.

* **Justification**: To maintain parity with the native libc `printf`, the code detects the OS at compile-time using `#ifdef __linux__`. This ensures the library outputs `(nil)` on Linux and `0x0` on macOS when a `NULL` pointer is passed, providing behavior identical to the host system.

---

4. Resources 

### References & Documentation

* **Personal Technical Blog**: [Restarting C - ft_printf Analysis (Korean)](https://velog.io/@vendredi/%EB%8B%A4%EC%8B%9C-%EC%8B%9C%EC%9E%91%ED%95%98%EB%8A%94-C-ep.0)
* **Test Suite**: [42-ft_printf-w-test](https://github.com/jihoon42/42-ft_printf-w-test) (A custom repository created to verify function robustness).
* **C Library Documentation**: Studied `printf(3)` and `stdarg(3)` man pages for variadic argument handling.

AI Usage Disclosure 

In compliance with the 42 AI policy, AI tools were utilized as a technical thought partner for the following tasks:

* **Architectural Refactoring**: Assisted in modularizing the `check_format` function to ensure it adheres to the 25-line limit required by the Norm.
* **Edge-Case Brainstorming**: Used to identify potential pitfalls regarding `INT_MIN` and the maximum range of `unsigned long long` types.
* **Documentation Refinement**: Assisted in structuring this README and refining the technical justifications to ensure clarity and professional presentation.
* 
**Countermeasures**: All AI-suggested logic was manually reviewed, understood, and tested in both macOS and Linux environments to ensure accuracy and compliance.

---
 
## 1. Description

`ft_printf`는 C 표준 라이브러리의 `printf()` 함수를 재구현하는 프로젝트입니다. 이 프로젝트의 주요 목표는 가변 인자(Variadic arguments)의 활용법을 익히고, 다양한 데이터 타입을 문자열로 변환하여 출력하는 포맷팅 로직을 설계하는 것입니다. 버퍼 관리 기능을 제외한 핵심 기능을 구현하며, 실제 libc의 `printf()`와 동일한 출력 결과를 보장하도록 설계되었습니다.

Supported Conversions 

* 
**%c**: 단일 문자 출력 


* 
**%s**: 문자열 출력 (NULL 포인터 시 `(null)` 처리) 


* 
**%p**: void 포인터의 16진수 주소값 출력 


* 
**%d / %i**: 부호 있는 10진수 정수 출력 


* 
**%u**: 부호 없는 10진수 정수 출력 


* 
**%x / %X**: 16진수 소문자/대문자 출력 


* 
**%%**: 퍼센트 기호 출력 



---

2. Instructions 

### Compilation

`Makefile`은 `cc` 컴파일러와 `-Wall -Wextra -Werror` 플래그를 사용하며, 불필요한 리링크(Relinking)를 방지하도록 작성되었습니다.

```bash
# [cite_start]libftprintf.a 라이브러리 생성 [cite: 96, 106]
make

# [cite_start]오브젝트 파일 및 라이브러리 삭제 [cite: 31]
make fclean

```

### Development Environment & Verification

* **작업 환경**: macOS (Apple M1 Pro) 및 42 클러스터 Ubuntu 환경에서 모두 검증을 완료하였습니다.
* 
**메모리 체크**: 힙 메모리 할당 시 누수(Memory Leak)가 발생하지 않도록 철저히 관리하였습니다.


* **macOS**: `leaks -atExit -- ./test` 와 같이 명령어를 통해 검증.
* **Ubuntu**: `valgrind --leak-check=full ./test` 와 같이 검증.



---

3. Algorithm and Data Structure (Justification) 

### 계층적 모듈화 (Modular Architecture)

코드의 가독성과 유지보수성을 높이기 위해 프로젝트를 **Printers(상위 로직)**와 **Utils(하위 유틸리티)** 계층으로 분리하였습니다.

* **Justification**: 각 서식 지정자(`%p`, `%x` 등)의 처리 로직을 독립된 파일로 구성함으로써, 특정 변환 규칙의 수정이 전체 시스템에 영향을 주지 않도록 설계하였습니다. 이는 서브젝트에서 강조하는 "확장 가능한 코드(Extensible code)"의 핵심입니다.



### 범용 베이스 변환 엔진 (`ft_putbase_ull`)

다양한 진법(10진수, 16진수 등) 출력을 처리하기 위해 `unsigned long long` 타입을 수용하는 범용 변환 함수를 구현하였습니다.

* **Justification**: `%u`, `%x`, `%X`, `%p`는 모두 숫자를 특정 진수로 표현한다는 공통점이 있습니다. 하나의 안정적인 베이스 변환 엔진을 공유함으로써 코드 중복을 최소화하고, 재귀 호출 방식을 통해 버퍼 할당 없이도 정확한 순서로 문자를 출력하도록 최적화하였습니다.

### OS 대응 매크로 처리

포인터(`%p`)의 NULL 값 처리 방식은 운영체제마다 상이합니다.

* **Justification**: `#ifdef __linux__` 매크로를 활용하여 Linux 환경에서는 `(nil)`을, 그 외 환경(macOS 등)에서는 `0x0`을 출력하도록 하여 libc의 실제 동작과 완벽히 일치하도록 구현하였습니다.

---

4. Resources 

References & Further Reading 

* **학습 정리**: [다시 시작하는 C - ft_printf 분석](https://velog.io/@vendredi/%EB%8B%A4%EC%8B%9C-%EC%8B%9C%EC%9E%91%ED%95%98%EB%8A%94-C-ep.0) (공부한 내용을 정리한 블로그 포스팅)
* **테스트 저장소**: [42-ft_printf-w-test](https://github.com/jihoon42/42-ft_printf-w-test) (함수 검증을 위해 직접 작성한 테스트 코드)
* 
**C11 Standard**: `printf`의 반환 값 및 에러 발생 시 처리 기준 수립을 위해 참고.



AI Usage Disclosure 

42 AI 가이드라인을 준수하여 다음과 같이 AI 도구를 활용하였습니다:

* **작업 범위**:
* **구조 설계 보조**: `check_format` 함수의 가독성을 높이기 위해 복잡한 조건문을 모듈화하는 리팩토링 과정에서 조언을 구함.
* **경계값 분석**: `INT_MIN` 처리 및 `unsigned long long`의 최대 범위에서 발생할 수 있는 잠재적 이슈를 식별하는 데 활용.
* **문서화 최적화**: 기술적 정당화(Justification) 섹션의 영문 표현 및 구조를 다듬어 가독성을 향상함.
