#include "constants.h"

struct IntConstantList {
    char *name;
    long val;
};

static int
PyModule_AddUnsignedLongConstant(PyObject *m, const char *name, unsigned long value)
{
    PyObject *o = PyLong_FromUnsignedLong(value);
    if (!o)
        return -1;
    if (PyModule_AddObject(m, name, o) == 0)
        return 0;
    Py_DECREF(o);
    return -1;
}

static int
PyModule_AddUnsignedLongLongConstant(PyObject *m, 
                                     const char *name, unsigned long long value)
{
    PyObject *o = PyLong_FromUnsignedLongLong(value);
    if (!o)
        return -1;
    if (PyModule_AddObject(m, name, o) == 0)
        return 0;
    Py_DECREF(o);
    return -1;
}

#define ConstTok(x) {#x, x}
void AddConstants(PyObject *m)
{
    struct IntConstantList clist[] = {
        ConstTok(DEBUG_ASMOPT_DEFAULT),
        ConstTok(DEBUG_ASMOPT_VERBOSE),
        ConstTok(DEBUG_ASMOPT_NO_CODE_BYTES),
        ConstTok(DEBUG_ASMOPT_IGNORE_OUTPUT_WIDTH),
        ConstTok(DEBUG_ASMOPT_SOURCE_LINE_NUMBER),
        ConstTok(DEBUG_ATTACH_DEFAULT),
        ConstTok(DEBUG_ATTACH_NONINVASIVE),
        ConstTok(DEBUG_ATTACH_EXISTING),
        ConstTok(DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND),
        ConstTok(DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK),
        ConstTok(DEBUG_ATTACH_INVASIVE_RESUME_PROCESS),
        ConstTok(DEBUG_ATTACH_NONINVASIVE_ALLOW_PARTIAL),
        ConstTok(DEBUG_ATTACH_KERNEL_CONNECTION),
        ConstTok(DEBUG_ATTACH_LOCAL_KERNEL),
        ConstTok(DEBUG_ATTACH_EXDI_DRIVER),
        ConstTok(DEBUG_CREATE_PROCESS_NO_DEBUG_HEAP),
        ConstTok(DEBUG_CREATE_PROCESS_THROUGH_RTL),
        ConstTok(DEBUG_PROCESS),
        ConstTok(DEBUG_ECREATE_PROCESS_DEFAULT),
        ConstTok(DEBUG_ECREATE_PROCESS_INHERIT_HANDLES),
        ConstTok(DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS),
        ConstTok(DEBUG_ECREATE_PROCESS_USE_IMPLICIT_COMMAND_LINE),
        ConstTok(DEBUG_CONNECT_SESSION_DEFAULT),
        ConstTok(DEBUG_CONNECT_SESSION_NO_VERSION),
        ConstTok(DEBUG_CONNECT_SESSION_NO_ANNOUNCE),
        ConstTok(DEBUG_SERVERS_DEBUGGER),
        ConstTok(DEBUG_SERVERS_PROCESS),
        ConstTok(DEBUG_SERVERS_ALL),
        ConstTok(DEBUG_END_PASSIVE),
        ConstTok(DEBUG_END_ACTIVE_TERMINATE),
        ConstTok(DEBUG_END_ACTIVE_DETACH),
        ConstTok(DEBUG_END_REENTRANT),
        ConstTok(DEBUG_END_DISCONNECT),
        ConstTok(DEBUG_DUMP_SMALL),
        ConstTok(DEBUG_DUMP_DEFAULT),
        ConstTok(DEBUG_DUMP_FULL),
        ConstTok(DEBUG_DUMP_IMAGE_FILE),
        ConstTok(DEBUG_DUMP_TRACE_LOG),
        ConstTok(DEBUG_KERNEL_CONNECTION),
        ConstTok(DEBUG_KERNEL_LOCAL),
        ConstTok(DEBUG_KERNEL_EXDI_DRIVER),
        ConstTok(DEBUG_KERNEL_SMALL_DUMP),
        ConstTok(DEBUG_KERNEL_DUMP),
        ConstTok(DEBUG_KERNEL_FULL_DUMP),
        ConstTok(DEBUG_KERNEL_TRACE_LOG),
        ConstTok(DEBUG_USER_WINDOWS_PROCESS),
        ConstTok(DEBUG_USER_WINDOWS_PROCESS_SERVER),
        ConstTok(DEBUG_USER_WINDOWS_SMALL_DUMP),
        ConstTok(DEBUG_USER_WINDOWS_DUMP),
        ConstTok(DEBUG_DUMP_FILE_BASE),
        ConstTok(DEBUG_DUMP_FILE_PAGE_FILE_DUMP),
        ConstTok(DEBUG_ENGOPT_IGNORE_DBGHELP_VERSION),
        ConstTok(DEBUG_ENGOPT_IGNORE_EXTENSION_VERSIONS),
        ConstTok(DEBUG_ENGOPT_ALLOW_NETWORK_PATHS),
        ConstTok(DEBUG_ENGOPT_DISALLOW_NETWORK_PATHS),
        ConstTok(DEBUG_ENGOPT_IGNORE_LOADER_EXCEPTIONS),
        ConstTok(DEBUG_ENGOPT_INITIAL_BREAK),
        ConstTok(DEBUG_ENGOPT_INITIAL_MODULE_BREAK),
        ConstTok(DEBUG_ENGOPT_FINAL_BREAK),
        ConstTok(DEBUG_ENGOPT_NO_EXECUTE_REPEAT),
        ConstTok(DEBUG_ENGOPT_FAIL_INCOMPLETE_INFORMATION),
        ConstTok(DEBUG_ENGOPT_ALLOW_READ_ONLY_BREAKPOINTS),
        ConstTok(DEBUG_ENGOPT_SYNCHRONIZE_BREAKPOINTS),
        ConstTok(DEBUG_ENGOPT_DISALLOW_SHELL_COMMANDS),
        ConstTok(DEBUG_ENGOPT_KD_QUIET_MODE),
        ConstTok(DEBUG_ENGOPT_DISABLE_MANAGED_SUPPORT),
        ConstTok(DEBUG_ENGOPT_DISABLE_MODULE_SYMBOL_LOAD),
        ConstTok(DEBUG_ENGOPT_DISABLE_EXECUTION_COMMANDS),
        ConstTok(DEBUG_ENGOPT_DISALLOW_IMAGE_FILE_MAPPING),
        ConstTok(DEBUG_ENGOPT_ALL),
        ConstTok(DEBUG_EVENT_BREAKPOINT),
        ConstTok(DEBUG_EVENT_EXCEPTION),
        ConstTok(DEBUG_EVENT_CREATE_THREAD),
        ConstTok(DEBUG_EVENT_EXIT_THREAD),
        ConstTok(DEBUG_EVENT_CREATE_PROCESS),
        ConstTok(DEBUG_EVENT_EXIT_PROCESS),
        ConstTok(DEBUG_EVENT_LOAD_MODULE),
        ConstTok(DEBUG_EVENT_UNLOAD_MODULE),
        ConstTok(DEBUG_EVENT_SYSTEM_ERROR),
        ConstTok(DEBUG_EVENT_SESSION_STATUS),
        ConstTok(DEBUG_EVENT_CHANGE_DEBUGGEE_STATE),
        ConstTok(DEBUG_EVENT_CHANGE_ENGINE_STATE),
        ConstTok(DEBUG_EVENT_CHANGE_SYMBOL_STATE),
        ConstTok(DEBUG_FILTER_CREATE_THREAD),
        ConstTok(DEBUG_FILTER_EXIT_THREAD),
        ConstTok(DEBUG_FILTER_CREATE_PROCESS),
        ConstTok(DEBUG_FILTER_EXIT_PROCESS),
        ConstTok(DEBUG_FILTER_LOAD_MODULE),
        ConstTok(DEBUG_FILTER_UNLOAD_MODULE),
        ConstTok(DEBUG_FILTER_SYSTEM_ERROR),
        ConstTok(DEBUG_FILTER_INITIAL_BREAKPOINT),
        ConstTok(DEBUG_FILTER_INITIAL_MODULE_LOAD),
        ConstTok(DEBUG_FILTER_DEBUGGEE_OUTPUT ),
        ConstTok(DEBUG_FILTER_BREAK),
        ConstTok(DEBUG_FILTER_SECOND_CHANCE_BREAK),
        ConstTok(DEBUG_FILTER_OUTPUT),
        ConstTok(DEBUG_FILTER_REMOVE),
        ConstTok(DEBUG_FILTER_IGNORE),
        ConstTok(DEBUG_FILTER_GO_HANDLED),
        ConstTok(DEBUG_FILTER_GO_NOT_HANDLED),
        ConstTok(DEBUG_FIND_SOURCE_DEFAULT),
        ConstTok(DEBUG_FIND_SOURCE_FULL_PATH),
        ConstTok(DEBUG_FIND_SOURCE_BEST_MATCH),
        ConstTok(DEBUG_FIND_SOURCE_NO_SRCSRV),
        ConstTok(DEBUG_FIND_SOURCE_TOKEN_LOOKUP),
        ConstTok(DEBUG_FORMAT_DEFAULT),
        ConstTok(DEBUG_FORMAT_CAB_SECONDARY_ALL_IMAGES),
        ConstTok(DEBUG_FORMAT_WRITE_CAB),
        ConstTok(DEBUG_FORMAT_CAB_SECONDARY_FILES),
        ConstTok(DEBUG_FORMAT_NO_OVERWRITE),
        ConstTok(DEBUG_FORMAT_USER_SMALL_FULL_MEMORY),
        ConstTok(DEBUG_FORMAT_USER_SMALL_HANDLE_DATA),
        ConstTok(DEBUG_FORMAT_USER_SMALL_UNLOADED_MODULES),
        ConstTok(DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY),
        ConstTok(DEBUG_FORMAT_USER_SMALL_DATA_SEGMENTS),
        ConstTok(DEBUG_FORMAT_USER_SMALL_FILTER_MEMORY),
        ConstTok(DEBUG_FORMAT_USER_SMALL_FILTER_PATHS),
        ConstTok(DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA),
        ConstTok(DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY),
        ConstTok(DEBUG_FORMAT_USER_SMALL_NO_OPTIONAL_DATA),
        ConstTok(DEBUG_FORMAT_USER_SMALL_FULL_MEMORY_INFO),
        ConstTok(DEBUG_FORMAT_USER_SMALL_THREAD_INFO),
        ConstTok(DEBUG_FORMAT_USER_SMALL_CODE_SEGMENTS),
        ConstTok(DEBUG_FORMAT_USER_SMALL_NO_AUXILIARY_STATE),
        ConstTok(DEBUG_FORMAT_USER_SMALL_FULL_AUXILIARY_STATE),
        ConstTok(DEBUG_FORMAT_USER_SMALL_IGNORE_INACCESSIBLE_MEM),
        ConstTok(DEBUG_MODULE_LOADED),
        ConstTok(DEBUG_MODULE_UNLOADED),
        ConstTok(DEBUG_MODULE_USER_MODE),
        ConstTok(DEBUG_MODULE_EXE_MODULE),
        ConstTok(DEBUG_MODULE_EXPLICIT),
        ConstTok(DEBUG_MODULE_SECONDARY),
        ConstTok(DEBUG_MODULE_SYNTHETIC),
        ConstTok(DEBUG_MODULE_SYM_BAD_CHECKSUM),
        ConstTok(DEBUG_SYMTYPE_NONE),
        ConstTok(DEBUG_SYMTYPE_COFF),
        ConstTok(DEBUG_SYMTYPE_CODEVIEW),
        ConstTok(DEBUG_SYMTYPE_PDB),
        ConstTok(DEBUG_SYMTYPE_EXPORT),
        ConstTok(DEBUG_SYMTYPE_DEFERRED),
        ConstTok(DEBUG_SYMTYPE_SYM),
        ConstTok(DEBUG_SYMTYPE_DIA),
        ConstTok(SYMOPT_CASE_INSENSITIVE),
        ConstTok(SYMOPT_UNDNAME),
        ConstTok(SYMOPT_DEFERRED_LOADS),
        ConstTok(SYMOPT_NO_CPP),
        ConstTok(SYMOPT_LOAD_LINES),
        ConstTok(SYMOPT_OMAP_FIND_NEAREST),
        ConstTok(SYMOPT_LOAD_ANYTHING),
        ConstTok(SYMOPT_IGNORE_CVREC),
        ConstTok(SYMOPT_NO_UNQUALIFIED_LOADS),
        ConstTok(SYMOPT_FAIL_CRITICAL_ERRORS),
        ConstTok(SYMOPT_EXACT_SYMBOLS),
        ConstTok(SYMOPT_ALLOW_ABSOLUTE_SYMBOLS),
        ConstTok(SYMOPT_IGNORE_NT_SYMPATH),
        ConstTok(SYMOPT_INCLUDE_32BIT_MODULES),
        ConstTok(SYMOPT_PUBLICS_ONLY),
        ConstTok(SYMOPT_NO_PUBLICS),
        ConstTok(SYMOPT_AUTO_PUBLICS),
        ConstTok(SYMOPT_NO_IMAGE_SEARCH),
        ConstTok(SYMOPT_SECURE),
        ConstTok(SYMOPT_NO_PROMPTS),
        ConstTok(SYMOPT_DEBUG),
        ConstTok(DEBUG_OUTCTL_THIS_CLIENT),
        ConstTok(DEBUG_OUTCTL_ALL_CLIENTS),
        ConstTok(DEBUG_OUTCTL_ALL_OTHER_CLIENTS),
        ConstTok(DEBUG_OUTCTL_IGNORE),
        ConstTok(DEBUG_OUTCTL_LOG_ONLY),
        ConstTok(DEBUG_OUTCTL_NOT_LOGGED),
        ConstTok(DEBUG_OUTCTL_OVERRIDE_MASK),
        ConstTok(DEBUG_OUTCTL_AMBIENT),
        ConstTok(DEBUG_OUTPUT_NORMAL),
        ConstTok(DEBUG_OUTPUT_ERROR),
        ConstTok(DEBUG_OUTPUT_WARNING),
        ConstTok(DEBUG_OUTPUT_VERBOSE),
        ConstTok(DEBUG_OUTPUT_PROMPT),
        ConstTok(DEBUG_OUTPUT_PROMPT_REGISTERS),
        ConstTok(DEBUG_OUTPUT_EXTENSION_WARNING),
        ConstTok(DEBUG_OUTPUT_DEBUGGEE),
        ConstTok(DEBUG_OUTPUT_DEBUGGEE_PROMPT),
        ConstTok(DEBUG_OUTPUT_SYMBOLS),
        ConstTok(DEBUG_OUTPUT_SYMBOLS_DEFAULT),
        ConstTok(DEBUG_OUTPUT_SYMBOLS_NO_NAMES),
        ConstTok(DEBUG_OUTPUT_SYMBOLS_NO_OFFSETS),
        ConstTok(DEBUG_OUTPUT_SYMBOLS_NO_VALUES),
        ConstTok(DEBUG_OUTPUT_SYMBOLS_NO_TYPES),
        ConstTok(DEBUG_PROCESS_DETACH_ON_EXIT),
        ConstTok(DEBUG_PROCESS_ONLY_THIS_PROCESS),
        ConstTok(DEBUG_REGISTERS_DEFAULT),
        ConstTok(DEBUG_REGISTERS_INT32),
        ConstTok(DEBUG_REGISTERS_INT64),
        ConstTok(DEBUG_REGISTERS_FLOAT),
        ConstTok(DEBUG_REGISTERS_ALL),
        ConstTok(DEBUG_REGISTER_SUB_REGISTER),
        ConstTok(DEBUG_REGSRC_DEBUGGEE),
        ConstTok(DEBUG_REGSRC_EXPLICIT),
        ConstTok(DEBUG_REGSRC_FRAME),
        ConstTok(DEBUG_STATUS_NO_CHANGE),
        ConstTok(DEBUG_STATUS_GO),
        ConstTok(DEBUG_STATUS_GO_HANDLED),
        ConstTok(DEBUG_STATUS_GO_NOT_HANDLED),
        ConstTok(DEBUG_STATUS_STEP_OVER),
        ConstTok(DEBUG_STATUS_STEP_INTO),
        ConstTok(DEBUG_STATUS_BREAK),
        ConstTok(DEBUG_STATUS_NO_DEBUGGEE),
        ConstTok(DEBUG_STATUS_STEP_BRANCH),
        ConstTok(DEBUG_STATUS_IGNORE_EVENT),
        ConstTok(DEBUG_STATUS_RESTART_REQUESTED),
        ConstTok(DEBUG_SYMBOL_EXPANSION_LEVEL_MASK),
        ConstTok(DEBUG_SYMBOL_EXPANDED),
        ConstTok(DEBUG_SYMBOL_READ_ONLY),
        ConstTok(DEBUG_SYMBOL_IS_ARRAY),
        ConstTok(DEBUG_SYMBOL_IS_FLOAT),
        ConstTok(DEBUG_SYMBOL_IS_ARGUMENT),
        ConstTok(DEBUG_SYMBOL_IS_LOCAL),
        ConstTok(DEBUG_SYMENT_IS_CODE),
        ConstTok(DEBUG_SYMENT_IS_DATA),
        ConstTok(DEBUG_SYMENT_IS_PARAMETER),
        ConstTok(DEBUG_SYMENT_IS_LOCAL),
        ConstTok(DEBUG_SYMENT_IS_MANAGED),
        ConstTok(DEBUG_SYMENT_IS_SYNTHETIC),
        ConstTok(DEBUG_TBINFO_EXIT_STATUS),
        ConstTok(DEBUG_TBINFO_PRIORITY_CLASS),
        ConstTok(DEBUG_TBINFO_PRIORITY),
        ConstTok(DEBUG_TBINFO_TIMES),
        ConstTok(DEBUG_TBINFO_START_OFFSET),
        ConstTok(DEBUG_TBINFO_AFFINITY),
        ConstTok(DEBUG_TBINFO_ALL),
        ConstTok(DEBUG_TYPEOPTS_UNICODE_DISPLAY),
        ConstTok(DEBUG_TYPEOPTS_LONGSTATUS_DISPLAY),
        ConstTok(DEBUG_TYPEOPTS_FORCERADIX_OUTPUT),
        ConstTok(DEBUG_TYPEOPTS_MATCH_MAXSIZE),
        ConstTok(S_OK),
        ConstTok(S_FALSE),
        ConstTok(E_FAIL),
        ConstTok(E_INVALIDARG),
        ConstTok(E_NOINTERFACE),
        ConstTok(E_OUTOFMEMORY ),
        ConstTok(E_UNEXPECTED),
        ConstTok(E_NOTIMPL ),
        ConstTok(DEBUG_BREAKPOINT_CODE),
        ConstTok(DEBUG_BREAKPOINT_DATA),
        ConstTok(DEBUG_BREAKPOINT_TIME),
        ConstTok(DEBUG_BREAKPOINT_GO_ONLY),
        ConstTok(DEBUG_BREAKPOINT_DEFERRED),
        ConstTok(DEBUG_BREAKPOINT_ENABLED),
        ConstTok(DEBUG_BREAKPOINT_ADDER_ONLY),
        ConstTok(DEBUG_BREAKPOINT_ONE_SHOT),
        ConstTok(DEBUG_BREAK_READ),
        ConstTok(DEBUG_BREAK_WRITE),
        ConstTok(DEBUG_BREAK_EXECUTE),
        ConstTok(DEBUG_BREAK_IO),
        ConstTok(DEBUG_CLASS_UNINITIALIZED),
        ConstTok(DEBUG_CLASS_KERNEL),
        ConstTok(DEBUG_CLASS_USER_WINDOWS),
        ConstTok(DEBUG_CLASS_IMAGE_FILE),
        ConstTok(DEBUG_INTERRUPT_ACTIVE),
        ConstTok(DEBUG_INTERRUPT_PASSIVE),
        ConstTok(DEBUG_INTERRUPT_EXIT),
        ConstTok(DEBUG_STACK_ARGUMENTS),
        ConstTok(DEBUG_STACK_FUNCTION_INFO),
        ConstTok(DEBUG_STACK_SOURCE_LINE),
        ConstTok(DEBUG_STACK_FRAME_ADDRESSES),
        ConstTok(DEBUG_STACK_COLUMN_NAMES),
        ConstTok(DEBUG_STACK_NONVOLATILE_REGISTERS),
        ConstTok(DEBUG_STACK_FRAME_NUMBERS),
        ConstTok(DEBUG_STACK_PARAMETERS),
        ConstTok(DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY),
        ConstTok(DEBUG_STACK_FRAME_MEMORY_USAGE),
        ConstTok(DEBUG_STACK_PARAMETERS_NEWLINE),
        ConstTok(DEBUG_STACK_FRAME_OFFSETS),
        ConstTok(DEBUG_CURRENT_SYMBOL),
        ConstTok(DEBUG_CURRENT_DISASM),
        ConstTok(DEBUG_CURRENT_REGISTERS),
        ConstTok(DEBUG_CURRENT_SOURCE_LINE),
        ConstTok(DEBUG_CURRENT_DEFAULT),
        ConstTok(DEBUG_DATA_KernBase),
        ConstTok(DEBUG_DATA_BreakpointWithStatusAddr),
        ConstTok(DEBUG_DATA_SavedContextAddr),
        ConstTok(DEBUG_DATA_KiCallUserModeAddr),
        ConstTok(DEBUG_DATA_KeUserCallbackDispatcherAddr),
        ConstTok(DEBUG_DATA_PsLoadedModuleListAddr),
        ConstTok(DEBUG_DATA_PsActiveProcessHeadAddr),
        ConstTok(DEBUG_DATA_PspCidTableAddr),
        ConstTok(DEBUG_DATA_ExpSystemResourcesListAddr),
        ConstTok(DEBUG_DATA_ExpPagedPoolDescriptorAddr),
        ConstTok(DEBUG_DATA_ExpNumberOfPagedPoolsAddr),
        ConstTok(DEBUG_DATA_KeTimeIncrementAddr),
        ConstTok(DEBUG_DATA_KeBugCheckCallbackListHeadAddr),
        ConstTok(DEBUG_DATA_KiBugcheckDataAddr),
        ConstTok(DEBUG_DATA_IopErrorLogListHeadAddr),
        ConstTok(DEBUG_DATA_ObpRootDirectoryObjectAddr),
        ConstTok(DEBUG_DATA_ObpTypeObjectTypeAddr),
        ConstTok(DEBUG_DATA_MmSystemCacheStartAddr),
        ConstTok(DEBUG_DATA_MmSystemCacheEndAddr),
        ConstTok(DEBUG_DATA_MmSystemCacheWsAddr),
        ConstTok(DEBUG_DATA_MmPfnDatabaseAddr),
        ConstTok(DEBUG_DATA_MmSystemPtesStartAddr),
        ConstTok(DEBUG_DATA_MmSystemPtesEndAddr),
        ConstTok(DEBUG_DATA_MmSubsectionBaseAddr),
        ConstTok(DEBUG_DATA_MmNumberOfPagingFilesAddr),
        ConstTok(DEBUG_DATA_MmLowestPhysicalPageAddr),
        ConstTok(DEBUG_DATA_MmHighestPhysicalPageAddr),
        ConstTok(DEBUG_DATA_MmNumberOfPhysicalPagesAddr),
        ConstTok(DEBUG_DATA_MmMaximumNonPagedPoolInBytesAddr),
        ConstTok(DEBUG_DATA_MmNonPagedSystemStartAddr),
        ConstTok(DEBUG_DATA_MmNonPagedPoolStartAddr),
        ConstTok(DEBUG_DATA_MmNonPagedPoolEndAddr),
        ConstTok(DEBUG_DATA_MmPagedPoolStartAddr),
        ConstTok(DEBUG_DATA_MmPagedPoolEndAddr),
        ConstTok(DEBUG_DATA_MmPagedPoolInformationAddr),
        ConstTok(DEBUG_DATA_MmPageSize),
        ConstTok(DEBUG_DATA_MmSizeOfPagedPoolInBytesAddr),
        ConstTok(DEBUG_DATA_MmTotalCommitLimitAddr),
        ConstTok(DEBUG_DATA_MmTotalCommittedPagesAddr),
        ConstTok(DEBUG_DATA_MmSharedCommitAddr),
        ConstTok(DEBUG_DATA_MmDriverCommitAddr),
        ConstTok(DEBUG_DATA_MmProcessCommitAddr),
        ConstTok(DEBUG_DATA_MmPagedPoolCommitAddr),
        ConstTok(DEBUG_DATA_MmExtendedCommitAddr),
        ConstTok(DEBUG_DATA_MmZeroedPageListHeadAddr),
        ConstTok(DEBUG_DATA_MmFreePageListHeadAddr),
        ConstTok(DEBUG_DATA_MmStandbyPageListHeadAddr),
        ConstTok(DEBUG_DATA_MmModifiedPageListHeadAddr),
        ConstTok(DEBUG_DATA_MmModifiedNoWritePageListHeadAddr),
        ConstTok(DEBUG_DATA_MmAvailablePagesAddr),
        ConstTok(DEBUG_DATA_MmResidentAvailablePagesAddr),
        ConstTok(DEBUG_DATA_PoolTrackTableAddr),
        ConstTok(DEBUG_DATA_NonPagedPoolDescriptorAddr),
        ConstTok(DEBUG_DATA_MmHighestUserAddressAddr),
        ConstTok(DEBUG_DATA_MmSystemRangeStartAddr),
        ConstTok(DEBUG_DATA_MmUserProbeAddressAddr),
        ConstTok(DEBUG_DATA_KdPrintCircularBufferAddr),
        ConstTok(DEBUG_DATA_KdPrintCircularBufferEndAddr),
        ConstTok(DEBUG_DATA_KdPrintWritePointerAddr),
        ConstTok(DEBUG_DATA_KdPrintRolloverCountAddr),
        ConstTok(DEBUG_DATA_MmLoadedUserImageListAddr),
        ConstTok(DEBUG_DATA_PaeEnabled),
        ConstTok(DEBUG_DATA_SharedUserData),
        ConstTok(DEBUG_DATA_ProductType),
        ConstTok(DEBUG_DATA_SuiteMask),
        ConstTok(DEBUG_DATA_DumpWriterStatus),
        ConstTok(DEBUG_DATA_NtBuildLabAddr),
        ConstTok(DEBUG_DATA_KiNormalSystemCall),
        ConstTok(DEBUG_DATA_KiProcessorBlockAddr),
        ConstTok(DEBUG_DATA_MmUnloadedDriversAddr),
        ConstTok(DEBUG_DATA_MmLastUnloadedDriverAddr),
        ConstTok(DEBUG_DATA_MmTriageActionTakenAddr),
        ConstTok(DEBUG_DATA_MmSpecialPoolTagAddr),
        ConstTok(DEBUG_DATA_KernelVerifierAddr),
        ConstTok(DEBUG_DATA_MmVerifierDataAddr),
        ConstTok(DEBUG_DATA_MmAllocatedNonPagedPoolAddr),
        ConstTok(DEBUG_DATA_MmPeakCommitmentAddr),
        ConstTok(DEBUG_DATA_MmTotalCommitLimitMaximumAddr),
        ConstTok(DEBUG_DATA_CmNtCSDVersionAddr),
        ConstTok(DEBUG_DATA_MmPhysicalMemoryBlockAddr),
        ConstTok(DEBUG_DATA_MmSessionBase),
        ConstTok(DEBUG_DATA_MmSessionSize),
        ConstTok(DEBUG_DATA_MmSystemParentTablePage),
        ConstTok(DEBUG_DATA_MmVirtualTranslationBase),
        ConstTok(DEBUG_DATA_OffsetKThreadNextProcessor),
        ConstTok(DEBUG_DATA_OffsetKThreadTeb),
        ConstTok(DEBUG_DATA_OffsetKThreadKernelStack),
        ConstTok(DEBUG_DATA_OffsetKThreadInitialStack),
        ConstTok(DEBUG_DATA_OffsetKThreadApcProcess),
        ConstTok(DEBUG_DATA_OffsetKThreadState),
        ConstTok(DEBUG_DATA_OffsetKThreadBStore),
        ConstTok(DEBUG_DATA_OffsetKThreadBStoreLimit),
        ConstTok(DEBUG_DATA_SizeEProcess),
        ConstTok(DEBUG_DATA_OffsetEprocessPeb),
        ConstTok(DEBUG_DATA_OffsetEprocessParentCID),
        ConstTok(DEBUG_DATA_OffsetEprocessDirectoryTableBase),
        ConstTok(DEBUG_DATA_SizePrcb),
        ConstTok(DEBUG_DATA_OffsetPrcbDpcRoutine),
        ConstTok(DEBUG_DATA_OffsetPrcbCurrentThread),
        ConstTok(DEBUG_DATA_OffsetPrcbMhz),
        ConstTok(DEBUG_DATA_OffsetPrcbCpuType),
        ConstTok(DEBUG_DATA_OffsetPrcbVendorString),
        ConstTok(DEBUG_DATA_OffsetPrcbProcessorState),
        ConstTok(DEBUG_DATA_OffsetPrcbNumber),
        ConstTok(DEBUG_DATA_SizeEThread),
        ConstTok(DEBUG_DATA_KdPrintCircularBufferPtrAddr),
        ConstTok(DEBUG_DATA_KdPrintBufferSizeAddr),
        ConstTok(DEBUG_DATA_KPCR_OFFSET),
        ConstTok(DEBUG_DATA_KPRCB_OFFSET),
        ConstTok(DEBUG_DATA_KTHREAD_OFFSET),
        ConstTok(DEBUG_DATA_BASE_TRANSLATION_VIRTUAL_OFFSET),
        ConstTok(DEBUG_DATA_PROCESSOR_IDENTIFICATION),
        ConstTok(DEBUG_DATA_PROCESSOR_SPEED),
        ConstTok(DEBUG_CDS_ALL),
        ConstTok(DEBUG_CDS_REGISTERS),
        ConstTok(DEBUG_CDS_DATA),
        ConstTok(DEBUG_DATA_SPACE_VIRTUAL),
        ConstTok(DEBUG_DATA_SPACE_PHYSICAL),
        ConstTok(DEBUG_DATA_SPACE_CONTROL),
        ConstTok(DEBUG_DATA_SPACE_IO),
        ConstTok(DEBUG_DATA_SPACE_MSR),
        ConstTok(DEBUG_DATA_SPACE_BUS_DATA),
        ConstTok(DEBUG_DATA_SPACE_DEBUGGER_DATA),
        ConstTok(DEBUG_CES_ALL),
        ConstTok(DEBUG_CES_CURRENT_THREAD),
        ConstTok(DEBUG_CES_EFFECTIVE_PROCESSOR),
        ConstTok(DEBUG_CES_BREAKPOINTS),
        ConstTok(DEBUG_CES_CODE_LEVEL),
        ConstTok(DEBUG_CES_EXECUTION_STATUS),
        ConstTok(DEBUG_CES_ENGINE_OPTIONS),
        ConstTok(DEBUG_CES_LOG_FILE),
        ConstTok(DEBUG_CES_RADIX),
        ConstTok(DEBUG_CES_EVENT_FILTERS),
        ConstTok(DEBUG_CES_PROCESS_OPTIONS),
        ConstTok(DEBUG_CES_EXTENSIONS),
        ConstTok(DEBUG_CES_SYSTEMS),
        ConstTok(DEBUG_CES_ASSEMBLY_OPTIONS),
        ConstTok(DEBUG_CES_EXPRESSION_SYNTAX),
        ConstTok(DEBUG_CES_TEXT_REPLACEMENTS),
        ConstTok(DEBUG_SESSION_ACTIVE),
        ConstTok(DEBUG_SESSION_END_SESSION_ACTIVE_TERMINATE),
        ConstTok(DEBUG_SESSION_END_SESSION_ACTIVE_DETACH),
        ConstTok(DEBUG_SESSION_END_SESSION_PASSIVE),
        ConstTok(DEBUG_SESSION_END),
        ConstTok(DEBUG_SESSION_REBOOT),
        ConstTok(DEBUG_SESSION_HIBERNATE),
        ConstTok(DEBUG_SESSION_FAILURE),
        ConstTok(DEBUG_CSS_ALL),
        ConstTok(DEBUG_CSS_LOADS),
        ConstTok(DEBUG_CSS_UNLOADS),
        ConstTok(DEBUG_CSS_SCOPE),
        ConstTok(DEBUG_CSS_PATHS),
        ConstTok(DEBUG_CSS_SYMBOL_OPTIONS),
        ConstTok(DEBUG_CSS_TYPE_OPTIONS),
        ConstTok(DEBUG_DISASM_EFFECTIVE_ADDRESS),
        ConstTok(DEBUG_DISASM_MATCHING_SYMBOLS),
        ConstTok(DEBUG_DISASM_SOURCE_LINE_NUMBER),
        ConstTok(DEBUG_DISASM_SOURCE_FILE_NAME),
        ConstTok(IMAGE_FILE_MACHINE_I386),
        ConstTok(IMAGE_FILE_MACHINE_ARM),
        ConstTok(IMAGE_FILE_MACHINE_IA64),
        ConstTok(IMAGE_FILE_MACHINE_AMD64),
        ConstTok(IMAGE_FILE_MACHINE_EBC),
        ConstTok(DEBUG_GET_PROC_DEFAULT),
        ConstTok(DEBUG_GET_PROC_FULL_MATCH),
        ConstTok(DEBUG_GET_PROC_ONLY_MATCH),
        ConstTok(DEBUG_GET_PROC_SERVICE_NAME),
        ConstTok(DEBUG_PROC_DESC_DEFAULT),
        ConstTok(DEBUG_PROC_DESC_NO_PATHS),
        ConstTok(DEBUG_PROC_DESC_NO_SERVICES),
        ConstTok(DEBUG_PROC_DESC_NO_MTS_PACKAGES),
        ConstTok(DEBUG_PROC_DESC_NO_COMMAND_LINE),
        ConstTok(DEBUG_PROC_DESC_NO_SESSION_ID),
        ConstTok(DEBUG_PROC_DESC_NO_USER_NAME),
        ConstTok(DEBUG_LEVEL_SOURCE),
        ConstTok(DEBUG_LEVEL_ASSEMBLY),
        ConstTok(DEBUG_EXTENSION_AT_ENGINE),
        ConstTok(DEBUG_EXECUTE_DEFAULT),
        ConstTok(DEBUG_EXECUTE_ECHO),
        ConstTok(DEBUG_EXECUTE_NOT_LOGGED),
        ConstTok(DEBUG_EXECUTE_NO_REPEAT),
        ConstTok(DEBUG_EXPR_MASM),
        ConstTok(DEBUG_EXPR_CPLUSPLUS),
        ConstTok(DEBUG_EINDEX_NAME),
        ConstTok(DEBUG_EINDEX_FROM_START),
        ConstTok(DEBUG_EINDEX_FROM_END),
        ConstTok(DEBUG_EINDEX_FROM_CURRENT),
        ConstTok(DEBUG_LOG_DEFAULT),
        ConstTok(DEBUG_LOG_APPEND),
        ConstTok(DEBUG_LOG_UNICODE),
        ConstTok(DEBUG_SYSVERSTR_SERVICE_PACK),
        ConstTok(DEBUG_SYSVERSTR_BUILD),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_BASIC),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_TYPE_NAME),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_HANDLE_COUNT),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_TYPE_NAME_WIDE),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME_WIDE),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_MINI_THREAD_1),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_1),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_2),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_PER_HANDLE_OPERATIONS),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_ALL_HANDLE_OPERATIONS),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_1),
        ConstTok(DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_2),
        ConstTok(DEBUG_OFFSINFO_VIRTUAL_SOURCE),
        ConstTok(DEBUG_VSOURCE_INVALID),
        ConstTok(DEBUG_VSOURCE_DEBUGGEE),
        ConstTok(DEBUG_VSOURCE_MAPPED_IMAGE),
        ConstTok(DEBUG_VSOURCE_DUMP_WITHOUT_MEMINFO),
        ConstTok(DEBUG_VSEARCH_DEFAULT),
        ConstTok(DEBUG_VSEARCH_WRITABLE_ONLY),
        ConstTok(DEBUG_PHYSICAL_DEFAULT),
        ConstTok(DEBUG_PHYSICAL_CACHED),
        ConstTok(DEBUG_PHYSICAL_UNCACHED),
        ConstTok(DEBUG_PHYSICAL_WRITE_COMBINED),
        ConstTok(DEBUG_SCOPE_GROUP_ARGUMENTS),
        ConstTok(DEBUG_SCOPE_GROUP_LOCALS),
        ConstTok(DEBUG_SCOPE_GROUP_ALL),
        ConstTok(DEBUG_OUTTYPE_DEFAULT),
        ConstTok(DEBUG_OUTTYPE_NO_INDENT),
        ConstTok(DEBUG_OUTTYPE_NO_OFFSET),
        ConstTok(DEBUG_OUTTYPE_VERBOSE),
        ConstTok(DEBUG_OUTTYPE_COMPACT_OUTPUT),
        ConstTok(DEBUG_OUTTYPE_ADDRESS_OF_FIELD),
        ConstTok(DEBUG_OUTTYPE_ADDRESS_AT_END),
        ConstTok(DEBUG_OUTTYPE_BLOCK_RECURSE),
        ConstTok(MODULE_ORDERS_MASK),
        ConstTok(MODULE_ORDERS_LOADTIME),
        ConstTok(MODULE_ORDERS_MODULENAME),
        ConstTok(DEBUG_MODNAME_IMAGE),
        ConstTok(DEBUG_MODNAME_MODULE),
        ConstTok(DEBUG_MODNAME_LOADED_IMAGE),
        ConstTok(DEBUG_MODNAME_SYMBOL_FILE),
        ConstTok(DEBUG_MODNAME_MAPPED_IMAGE),
        ConstTok(DEBUG_GETMOD_DEFAULT),
        ConstTok(DEBUG_GETMOD_NO_LOADED_MODULES),
        ConstTok(DEBUG_GETMOD_NO_UNLOADED_MODULES),
        ConstTok(DEBUG_ADDSYNTHMOD_DEFAULT),
        ConstTok(DEBUG_ADDSYNTHSYM_DEFAULT),
        ConstTok(DEBUG_OUTSYM_DEFAULT),
        ConstTok(DEBUG_OUTSYM_FORCE_OFFSET),
        ConstTok(DEBUG_OUTSYM_SOURCE_LINE),
        ConstTok(DEBUG_OUTSYM_ALLOW_DISPLACEMENT),
        ConstTok(DEBUG_GETFNENT_DEFAULT),
        ConstTok(DEBUG_GETFNENT_RAW_ENTRY_ONLY),
        ConstTok(DEBUG_SOURCE_IS_STATEMENT),
        ConstTok(DEBUG_GSEL_DEFAULT),
        ConstTok(DEBUG_GSEL_NO_SYMBOL_LOADS),
        ConstTok(DEBUG_GSEL_ALLOW_LOWER),
        ConstTok(DEBUG_GSEL_ALLOW_HIGHER),
        ConstTok(DEBUG_GSEL_NEAREST_ONLY),
        ConstTok(DEBUG_ANY_ID),
        ConstTok(STILL_ACTIVE),
        ConstTok(INFINITE),
        ConstTok(DEBUG_WAIT_DEFAULT),
        ConstTok(DEBUG_CREATE),
        ConstTok(DEBUG_CONNECT),

        {NULL},

        // WbgExts.h
        //{"DEBUG_TYPED_DATA_IS_IN_MEMORY", DEBUG_TYPED_DATA_IS_IN_MEMORY},
        //{"DEBUG_TYPED_DATA_PHYSICAL_DEFAULT", DEBUG_TYPED_DATA_PHYSICAL_DEFAULT},
        //{"DEBUG_TYPED_DATA_PHYSICAL_CACHED", DEBUG_TYPED_DATA_PHYSICAL_CACHED},
        //{"DEBUG_TYPED_DATA_PHYSICAL_UNCACHED", DEBUG_TYPED_DATA_PHYSICAL_UNCACHED},
        //{"DEBUG_TYPED_DATA_PHYSICAL_WRITE_COMBINED",
        //    DEBUG_TYPED_DATA_PHYSICAL_WRITE_COMBINED},
    };
    int i;
    for (i = 0; clist[i].name != NULL; i++)
        PyModule_AddUnsignedLongConstant(m, clist[i].name, clist[i].val);

    PyModule_AddUnsignedLongLongConstant(m, 
        "DEBUG_INVALID_OFFSET", DEBUG_INVALID_OFFSET);
    PyModule_AddUnsignedLongLongConstant(m, 
        "DEBUG_STATUS_INSIDE_WAIT", DEBUG_STATUS_INSIDE_WAIT);
    PyModule_AddUnsignedLongLongConstant(m, 
        "DEBUG_STATUS_WAIT_TIMEOUT", DEBUG_STATUS_WAIT_TIMEOUT);
}

