#pragma once

#define DISABLED_COPY(type) public: type(const type&) = delete; type& operator=(const type&) = delete;
#define DISABLED_MOVE(type) public: type(type&&) = delete; type& operator=(type&&) = delete;

// Attributes
#define	_NORETURN		[[noreturn]]
#define	_DEPRECATED		[[deprecated]]
#define	_MAYBE_UNUSED	[[maybe_unused]]
#define	_FALLTHROUGH	[[fallthrough]]
#define	_NODISCARD		[[nodiscard]]

#define	_INLINE			inline

#define _OWNER_PTR
#define	_DO_NOT_DELETE	/* copyed pointer */	
#define	_NOT_NULLPTR	